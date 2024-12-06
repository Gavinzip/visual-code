#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <errno.h>

#define MAX_LINE 1024

// 函數：將主機名轉換為 IP 位址
in_addr_t my_inet_addr(char *host) {
    in_addr_t inaddr;
    struct hostent *hp;

    inaddr = inet_addr(host);
    if (inaddr == INADDR_NONE && (hp = gethostbyname(host)) != NULL) {
        bcopy(hp->h_addr, (char *)&inaddr, hp->h_length);
    }
    return inaddr;
}

// 函數：開啟 TCP 連線
int tcp_open_client(char *host, char *port) {
    int sockfd;
    struct sockaddr_in serv_addr;

    // 初始化 serv_addr 結構體
    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = my_inet_addr(host);
    serv_addr.sin_port = htons(atoi(port));

    // 建立 socket 並連接伺服器
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0 ||
        connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        return -1; // 連接失敗
    }
    return sockfd; // 返回 socket 描述符
}

// 函數：檢查檔案描述符是否可讀
int readready(int fd) {
    fd_set map;
    int ret;
    struct timeval zerotimeval = {0, 0};

    do {
        FD_ZERO(&map);
        FD_SET(fd, &map);
        ret = select(fd + 1, &map, NULL, NULL, &zerotimeval);
        if (ret >= 0) return ret;
    } while (errno == EINTR);
    return ret;
}

// 函數：讀取一行文字
int readline(int fd, char *ptr, int maxlen) {
    int n, rc;
    char c;

    for (n = 1; n < maxlen; n++) {
        if ((rc = read(fd, &c, 1)) == 1) {
            *ptr++ = c;
            if (c == '\n') break; // 完成讀取一行
        } else if (rc == 0) {
            if (n == 1) return 0; // EOF，沒有讀到資料
            else break;          // EOF，已讀取部分資料
        } else {
            return -1; // 發生錯誤
        }
    }
    *ptr = 0;
    return n; // 返回讀取的字元數
}

// 函數：解析 URL 並拆分為主機、埠號與路徑
int parse_url(const char *url, char *host, char *port, char *path) {
    char *url_cpy = strdup(url);
    char *p;

    if (strncmp(url_cpy, "http://", 7) == 0) {
        url_cpy += 7; // 去掉 "http://"
    }

    // 提取主機名
    p = strchr(url_cpy, '/');
    if (p) {
        strcpy(path, p); // 路徑
        *p = '\0';
    } else {
        strcpy(path, "/");
    }

    // 提取埠號（若有）
    p = strchr(url_cpy, ':');
    if (p) {
        *p = '\0';
        strcpy(port, p + 1);
    } else {
        strcpy(port, "80"); // 預設 HTTP 埠號
    }

    strcpy(host, url_cpy);
    return 0;
}

// 主函數：webget.c 的執行流程
int main(int argc, char *argv[]) {
    int sockfd, len, ret;
    char buf[MAX_LINE];
    char host[MAX_LINE], port[6], path[MAX_LINE];
    int in_header = 1; // 用於判斷是否仍在 HTTP 標頭中

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        exit(1);
    }

    // 解析 URL
    if (parse_url(argv[1], host, port, path) != 0) {
        fprintf(stderr, "Invalid URL format\n");
        exit(1);
    }

    // 開啟與伺服器的 TCP 連線
    sockfd = tcp_open_client(host, port);
    if (sockfd < 0) {
        perror("Connection failed");
        exit(2);
    }

    // 發送完整的 HTTP GET 請求
    snprintf(buf, sizeof(buf), 
             "GET %s HTTP/1.0\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n"
             "\r\n", path, host);
    write(sockfd, buf, strlen(buf));

    // 接收伺服器回應並輸出
    while (1) {
        if ((ret = readready(sockfd)) < 0) break; // 等待伺服器訊息
        if (ret > 0) {
            if ((len = readline(sockfd, buf, MAX_LINE)) <= 0) break; // 讀取伺服器回應

            if (in_header) {
                // 檢查是否為空行（表示標頭結束）
                if (strcmp(buf, "\r\n") == 0) {
                    in_header = 0; // 標頭結束
                    continue;
                }

                // 過濾不需要的標頭
                if (strncasecmp(buf, "Date:", 5) == 0 ||
                    strncasecmp(buf, "ETag:", 5) == 0 ||
                    strncasecmp(buf, "Accept-Ranges:", 14) == 0) {
                    continue; // 跳過這些標頭
                }
            }

            fputs(buf, stdout); // 輸出到終端
        }
    }

    // 關閉 socket
    close(sockfd);
    return 0;
}