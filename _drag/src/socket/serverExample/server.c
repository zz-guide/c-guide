//
// Created by xulei on 2021/11/27.
//

#include "server.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <errno.h>


#define PORT 20000
#define IP "127.0.0.1"
#define BUF_SIZE 1024

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}

/**
 * 阻塞，非阻塞
 * 同步，异步
 *
 * accept一次只能处理一个客户端
 * 1.被动的监听客户端发起的请求。从等待队列中获取一个连接
 * 2.默认是阻塞的，没有连接一直阻塞。
 * 3.可以修改为非阻塞模式，无论是否有结果会直接返回
 */


int main(int argc, char *argv[]){
    // socket阶段，第一个参数为IP地址，第二个参数传输方式，第三个参数为具体的协议，0表示由操作系统自行选择，或者IPPROTO_TCP等
    int serverSocket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    // 返回值-1表示error
    if(serverSocket == -1) {
        error_handling("socket() error!");
    }

    // 设置socket为非阻塞模式
    int flags;
    if ((flags = fcntl(serverSocket, F_GETFL, NULL)) < 0) {
        return -1;
    }
    if (fcntl(serverSocket, F_SETFL, flags | O_NONBLOCK) == -1) {
        return -1;
    }

    // 准备一个 sockaddr_in 结构，初始化内存为0
    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(IP); // ip转地址
    serverAddr.sin_port = htons(PORT);    // 端口转换字节序

    // bind阶段，绑定socket到ip端口
    if(bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1) {
        error_handling("bind() error!");
    }

    // listen阶段，并设置backlog,同时能处理的最大连接要求,
    if(listen(serverSocket, 1) == -1) {
        error_handling("listen() error!");
    }

    struct sockaddr_in clientAddr;
    socklen_t clientSocketLen = sizeof(clientAddr);
    char message[BUF_SIZE];
    while(1) {
        printf("等待客户端接入....\n");
        int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &clientSocketLen);
        // 非阻塞直接返回
        if(clientSocket < 0) {
            if (errno==EAGAIN || errno == EWOULDBLOCK)
            {
                printf("没有新连接\n");
                sleep(2);
                continue;
            } else {
                error_handling("accept() error!");
                break;
            }

        } else {
            printf("Connected client fd=%d \n", clientSocket);
        }

        sleep(1);
        // 先读取客户端发送过来的数据
        if (read(clientSocket, message, BUF_SIZE) != -1) {
            printf("服务端接收消息: %s \n", message);
        } else {
            printf("服务端读取失败\n");
        }

        sleep(1);
        if (write(clientSocket, message, strlen(message)) != 0 ) {
            printf("写入客户端消息: %s \n", message);
        } else{
            printf("服务端写入失败\n");
        }

        sleep(3);
        close(clientSocket);
    }

    close(serverSocket);
    return 0;
}