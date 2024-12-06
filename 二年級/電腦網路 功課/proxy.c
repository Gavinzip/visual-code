#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>

#define MAX_LINE 1024
#define DEFAULT_PORT 8080

// 處理 SIGCHLD，避免僵屍進程
void handle_sigchld(int signo) {
    while (waitpid(-1, NULL, WNOHANG) > 0);
}

// 將主機名轉換為 IP 位址
in_addr_t my_inet_addr(char *host) {
    in_addr_t inaddr;
    struct hostent *hp;

    inaddr = inet_addr(host);
    if (inaddr == INADDR_NONE && (hp = gethostbyname(host)) != NULL) {
        bcopy(hp->h_addr, (char *)&inaddr, hp->h_length);
    }
    return inaddr;
}

// 開啟 TCP 連線
int tcp_open_client(char *host, char *port) {
    int sockfd;
    struct sockaddr_in serv_addr;

    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = my_inet_addr(host);
    serv_addr.sin_port = htons(atoi(port));

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 ||
        connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        return -1;
    }
    return sockfd;
}

// 啟動 TCP 伺服器
int tcp_open_server(int port) {
    int sockfd;
    struct sockaddr_in serv_addr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) return -1;

    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        return -1;

    listen(sockfd, 5);
    return sockfd;
}

// 檢查文件描述符是否可讀
int readready(int fd) {
    fd_set map;
    struct timeval zerotimeval = {0, 0};

    FD_ZERO(&map);
    FD_SET(fd, &map);

    return select(fd + 1, &map, NULL, NULL, &zerotimeval);
}

// 讀取一行文字
int readline(int fd, char *ptr, int maxlen) {
    int n, rc;
    char c;

    for (n = 1; n < maxlen; n++) {
        if ((rc = read(fd, &c, 1)) == 1) {
            *ptr++ = c;
            if (c == '\n') break;
        } else if (rc == 0) {
            if (n == 1) return 0;
            else break;
        } else {
            return -1;
        }
    }
    *ptr = 0;
    return n;
}

// 解析 URL
int parse_url(const char *url, char *host, char *port, char *path) {
    char *url_cpy = strdup(url);
    char *p;

    if (strncmp(url_cpy, "http://", 7) == 0) {
        url_cpy += 7;
    }

    p = strchr(url_cpy, '/');
    if (p) {
        strcpy(path, p);
        *p = '\0';
    } else {
        strcpy(path, "/");
    }

    p = strchr(url_cpy, ':');
    if (p) {
        *p = '\0';
        strcpy(port, p + 1);
    } else {
        strcpy(port, "80");
    }

    strcpy(host, url_cpy);
    return 0;
}

// 處理請求並轉發
void handle_request(int client_fd) {
    char buf[MAX_LINE];
    char method[MAX_LINE], url[MAX_LINE], protocol[MAX_LINE];
    char host[MAX_LINE], port[6], path[MAX_LINE];
    int server_fd, len;

    // 讀取客戶端請求
    if (readline(client_fd, buf, MAX_LINE) <= 0) return;

    // 解析請求行
    if (sscanf(buf, "%s %s %s", method, url, protocol) != 3) return;

    // 僅支援 GET 方法
    if (strcasecmp(method, "GET") != 0) {
        snprintf(buf, sizeof(buf), "HTTP/1.0 405 Method Not Allowed\r\n\r\n");
        write(client_fd, buf, strlen(buf));
        return;
    }

    // 解析 URL
    if (parse_url(url, host, port, path) != 0) return;

    // 連接目標伺服器
    server_fd = tcp_open_client(host, port);
    if (server_fd < 0) {
        snprintf(buf, sizeof(buf), "HTTP/1.0 502 Bad Gateway\r\n\r\n");
        write(client_fd, buf, strlen(buf));
        return;
    }

    // 發送 HTTP 請求至目標伺服器
    snprintf(buf, sizeof(buf),
             "GET %s HTTP/1.0\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n"
             "\r\n", path, host);
    write(server_fd, buf, strlen(buf));

    // 轉發伺服器響應給客戶端
    while ((len = read(server_fd, buf, MAX_LINE)) > 0) {
        write(client_fd, buf, len);
    }

    close(server_fd);
}

int main(int argc, char *argv[]) {
    int port = DEFAULT_PORT;
    int sockfd, newsockfd;
    socklen_t clilen;
    struct sockaddr_in cli_addr;

    if (argc == 2) {
        port = atoi(argv[1]);
    }

    signal(SIGCHLD, handle_sigchld);

    sockfd = tcp_open_server(port);
    if (sockfd < 0) {
        perror("Failed to open server");
        return 1;
    }

    printf("Proxy server running on port %d\n", port);

    for (;;) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (newsockfd < 0) continue;

        if (fork() == 0) {
            close(sockfd);
            handle_request(newsockfd);
            close(newsockfd);
            exit(0);
        }
        close(newsockfd);
    }
}