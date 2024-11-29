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

// 主函數：client.c 的執行流程
int main(int argc, char *argv[]) {
    int sockfd, len, ret;
    char buf[MAX_LINE];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    // 開啟與伺服器的 TCP 連線
    sockfd = tcp_open_client(argv[1], argv[2]);
    if (sockfd < 0) {
        perror("Connection failed");
        exit(2);
    }

    // 發送完整的 HTTP GET 請求
    snprintf(buf, sizeof(buf), 
             "GET / HTTP/1.0\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n"
             "\r\n", argv[1]);
    write(sockfd, buf, strlen(buf));

    // 接收伺服器回應並輸出
    while (1) {
        if ((ret = readready(sockfd)) < 0) break; // 等待伺服器訊息
        if (ret > 0) {
            if (readline(sockfd, buf, MAX_LINE) <= 0) break; // 讀取伺服器回應
            fputs(buf, stdout); // 輸出到終端
        }
    }

    // 關閉 socket
    close(sockfd);
    return 0;
}