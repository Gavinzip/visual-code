#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_LINE 1024

// 建立 TCP 伺服器並返回 socket 描述符
int tcp_open_server(char *port) {
    int sockfd;
    struct sockaddr_in serv_addr;

    // 創建 TCP Socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        return -1;
    }

    // 初始化地址結構
    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); // 綁定到所有本地地址
    serv_addr.sin_port = htons(atoi(port));       // 指定埠號

    // 綁定地址
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        return -1;
    }

    // 開始監聽
    if (listen(sockfd, 5) < 0) {
        perror("Listen failed");
        close(sockfd);
        return -1;
    }

    printf("Server listening on port %s...\n", port);
    return sockfd;
}

// 處理客戶端請求
void do_main(int newsockfd) {
    int ret;
    char buf[MAX_LINE];

    while ((ret = read(newsockfd, buf, MAX_LINE)) > 0) {
        buf[ret] = '\0'; // 確保字符串結尾
        printf("Received: %s\n", buf);

        if (strncmp(buf, "QUIT", 4) == 0) {
            printf("Client requested to quit.\n");
            break;
        } else if (strncmp(buf, "GET", 3) == 0) {
            char *response =
                "HTTP/1.0 200 OK\r\n"
                "Content-Type: text/plain\r\n"
                "\r\nHello, World!\n";
            send(newsockfd, response, strlen(response), 0);
        } else {
            char *error_msg = "Unknown command\n";
            send(newsockfd, error_msg, strlen(error_msg), 0);
        }
    }

    printf("Closing connection...\n");
    close(newsockfd);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int sockfd, newsockfd;
    socklen_t clilen;
    struct sockaddr_in cli_addr;

    // 初始化 TCP 伺服器
    sockfd = tcp_open_server(argv[1]);
    if (sockfd < 0) {
        exit(1);
    }

    for (;;) {
        clilen = sizeof(cli_addr);

        // 等待客戶端連接
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (newsockfd < 0) {
            perror("Accept failed");
            continue;
        }

        printf("Connection established with %s:%d\n",
               inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        // 創建子進程處理連接
        if (fork() == 0) {
            close(sockfd);          // 子進程不需要監聽 socket
            do_main(newsockfd);     // 處理請求
            exit(0);                // 結束子進程
        }
        close(newsockfd);           // 父進程關閉子進程使用的 socket
    }

    close(sockfd);
    return 0;
}