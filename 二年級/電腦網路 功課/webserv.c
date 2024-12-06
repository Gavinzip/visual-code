#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>

#define MAX_LINE 1024
#define DEFAULT_PORT 8080 // 預設埠號改為 8081

// 處理 SIGCHLD，避免僵屍進程
void handle_sigchld(int signo) {
    while (waitpid(-1, NULL, WNOHANG) > 0);
}

// 檢查文件描述符是否有數據準備好
int readready(int fd) {
    fd_set map;
    struct timeval _zerotimeval = {0, 0};
    FD_ZERO(&map);
    FD_SET(fd, &map);
    return select(fd + 1, &map, NULL, NULL, &_zerotimeval);
}

// 讀取一行數據
int readline(int fd, char *ptr, int maxlen) {
    int n, rc;
    char c;
    for (n = 1; n < maxlen; n++) {
        if ((rc = read(fd, &c, 1)) == 1) {
            *ptr++ = c;
            if (c == '\n') break;
        } else if (rc == 0) {
            if (n == 1) return 0; /* EOF, no data read */
            else break; /* EOF, some data read */
        } else {
            return -1; /* Error */
        }
    }
    *ptr = 0;
    return n;
}

void do_main(int newsockfd) {
    int ret;
    char buf[MAX_LINE];
    char method[MAX_LINE], path[MAX_LINE];

    while ((ret = readready(newsockfd)) >= 0) {
        if (ret == 0) continue;
    if (readline(newsockfd, buf, MAX_LINE) <= 0) break;
        fputs(buf, stdout);

        // 解析 HTTP 方法與路徑
        if (sscanf(buf, "%s %s", method, path) == 2) {
            if (strncmp(method, "GET", 3) == 0) {
                if (strcmp(path, "/mytest.htm") == 0) {
                    // 回傳指定 HTML 內容
                    char *response =
                        "HTTP/1.0 200 OK\r\n"
                        "Content-Type: text/html\r\n"
                        "\r\n"
                        "<html><body>"
                        "Welcome! I'm A1085501 from Taiwan."
                        "</body></html>\r\n";
                    send(newsockfd, response, strlen(response), 0);
                } else {
                    // 回傳 404 錯誤
                    char *response =
                        "HTTP/1.0 404 Not Found\r\n"
                        "Content-Type: text/html\r\n"
                        "\r\n"
                        "<html><body>"
                        "404 Not Found"
                        "</body></html>\r\n";
                    send(newsockfd, response, strlen(response), 0);
                }
                break; // 結束處理
            }
        }

        // 跳過其他請求標頭
        while (readline(newsockfd, buf, MAX_LINE) > 0) {
            if (strcmp(buf, "\r\n") == 0) break;
        }
    }

    // 在處理完成後正確關閉連線
    shutdown(newsockfd, SHUT_RDWR);
    close(newsockfd);
}
// 啟動 TCP 伺服器
int tcp_open_server(int port) {
    int sockfd;
    struct sockaddr_in serv_addr;
    /* Open a TCP socket (an Internet stream socket). */
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) return -1;
    /* Bind our local address so that the client can send to us. */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(port);
    if (bind(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0)
        return -1;
    listen(sockfd, 5);
    return sockfd;
}

int main(int argc, char *argv[]) {
    int port = DEFAULT_PORT; // 預設埠號為 8081
    if (argc == 2) {
        port = atoi(argv[1]); // 使用命令列參數設定埠號
    }
    
    // 處理 SIGCHLD 避免僵屍進程
    signal(SIGCHLD, handle_sigchld);
    
    int sockfd, newsockfd, childpid;
    socklen_t clilen; // 修正為 socklen_t 類型
    struct sockaddr_in cli_addr;
    sockfd = tcp_open_server(port);
    if (sockfd < 0) {
        perror("Failed to open server");
        return 1;
    }

    printf("Server running on port %d\n", port);

    for (;;) {
        /* 等待客戶端的連接 (並發伺服器) */
        clilen = sizeof(cli_addr);
        newsockfd = accept(sockfd, (struct sockaddr*) &cli_addr, &clilen);
        if (newsockfd < 0) continue; /* server: accept error */
        if ((childpid = fork()) < 0) continue; /* server: fork error */
        if (childpid == 0) { /* 子進程 */
            close(sockfd); /* 關閉原始 socket */
            do_main(newsockfd); /* 處理請求 */
            exit(0);
        }
        close(newsockfd); /* 父進程 */
    }
}