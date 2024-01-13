//
// Created by xulei on 2021/11/27.
//

/*
 * UNIX Domain Socket
 * 1.socket API原本是为网络通讯设计的，但后来在socket的框架上发展出一种IPC机
    制，就是UNIX Domain Socket。
   2.虽然网络socket也可用于同一台主机的进程间通讯（通过loopback地址127.0.0.1），但是UNIX Domain Socket用于IPC更有效率：不需要经过网络协
    议栈，不需要打包拆包、计算校验和、维护序号和应答等，只是将应用层数据从一个进程拷贝到另一个进程。这是因为，IPC机制本质上是可靠的通讯，而网络协议是为不可靠的通讯设计的。
   3.UNIX Domain Socket也提供面向流和面向数据包两种API接口，类似于TCP和UDP，但是面向消息的UNIX Domain Socket也是可靠的，消息既不会丢失也不会顺序错乱。
*/

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/mman.h>
#include <signal.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <net/if.h>
#include <sys/un.h>
#include <stddef.h>

//fd是监听socket,len是初始化socket地址的长度、err临时保存错误码
int fd;
int len;
int err;
int new_fd;

#define MAX_CONNECT_NUM 2
#define BUFFER_SIZE 1024
const char *filename = "uds-tmp";

void endDomainSocket() {
    close(fd);
}

int serv_accept() {
    while (1) {
        char buffer[BUFFER_SIZE];
        bzero(buffer, BUFFER_SIZE);

        struct sockaddr_un client_addr, clnt_addr;
        socklen_t client_addr_size = sizeof(clnt_addr);
        printf("开始阻塞\n");
        new_fd = accept(fd, (struct sockaddr *)&client_addr, &client_addr_size);
        if (new_fd < 0) {
            printf("accept失败\n");
            return -1;
        }

        // 使用recv
        ssize_t ret = recv(new_fd, buffer, BUFFER_SIZE, 0);
        // 使用read
//        ssize_t ret = read(new_fd, buffer, BUFFER_SIZE);
        if (ret < 0) {
            printf("recv失败 \n");
            return -1;
        }

        printf("服务接收的数据=%s\n\n", buffer);
        close(new_fd);
//        break;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    // 创建unix domain socket 服务
    struct sockaddr_un un;

    // 1.创建socket
    fd = socket(PF_UNIX, SOCK_STREAM, 0);
    if (fd < 0) {
        printf("创建socket失败\n");
        return -1;
    }

    // 2.如果socket文件已经存在，先删除
    unlink(filename);

    // 3.初始化socket的地址
    memset(&un, 0, sizeof(un));
    un.sun_family = AF_UNIX;
    strcpy(un.sun_path, filename);

    if (bind(fd, (struct sockaddr *) &un, sizeof(un)) < 0) {
        printf("bind失败\n");
        endDomainSocket();
        return -2;
    }

    // 4.监听
    if (listen(fd, MAX_CONNECT_NUM) < 0) {
        printf("listen失败\n");
        endDomainSocket();
        return -3;
    }

    serv_accept();
    endDomainSocket();
    return 0;
}

