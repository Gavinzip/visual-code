#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t addrLen = sizeof(clientAddr);

    // 創建伺服器套接字
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        perror("Socket creation failed");
        return 1;
    }

    // 設置伺服器地址和埠
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(8081);

    // 綁定地址到套接字
    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1) {
        perror("Bind failed");
        close(serverSocket);
        return 1;
    }

    // 監聽客戶端
    if (listen(serverSocket, 5) == -1) {
        perror("Listen failed");
        close(serverSocket);
        return 1;
    }
    printf("Server is listening on port 8081...\n");

    // 接受客戶端連接
    clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &addrLen);
    if (clientSocket == -1) {
        perror("Accept failed");
        close(serverSocket);
        return 1;
    }
    printf("Client connected!\n");

    // 關閉套接字
    close(clientSocket);
    close(serverSocket);

    return 0;
}