//
// Created by xulei on 2021/11/27.
//

#include "client.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 20000
#define IP "127.0.0.1"

void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}

/**
 *
 * 1.write,read,recv,send区别
 *  write,read通用方法
 *  recv,send只能用于socket,还多一个flags参数，用来控制是阻塞还是非阻塞的,flags为0的话2者没有区别
 */


int main(int argc, char *argv[]){
    // 1.socket阶段
    int clientSocket = socket(PF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        error_handling("socket() error");
    }

    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = inet_addr(IP);
    serverAddr.sin_port = htons(PORT);

    // connect阶段
    if (connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1) {
        error_handling("connect() error!");
    }

    char *message = "hello!";
    // if (send(clientSocket, message, strlen(message), 0) != 0) {
    if (send(clientSocket, message, strlen(message), MSG_DONTWAIT) != 0) {
        printf("客户端写入成功\n");
    } else {
        error_handling("客户端写入失败\n");
    }

    sleep(3);

    char newMessage[100];
    memset(newMessage, 0, sizeof(newMessage));
    // if (recv(clientSocket, newMessage, strlen(message), 0) != -1) {
    if (recv(clientSocket, newMessage, strlen(message), MSG_DONTWAIT) != -1) {
        printf("读取来自服务端消息: %s \n", newMessage);
    } else {
        error_handling("读取失败\n");
    }

    close(clientSocket);
    return 0;
}