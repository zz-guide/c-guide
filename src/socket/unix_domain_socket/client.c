//
// Created by xulei on 2021/11/27.
//

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

const char *filename = "uds-tmp";
#define BUFFER_SIZE 1024

int main() {
    int sock_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        printf("Request socket failed\n");
        return -1;
    }

    struct sockaddr_un un;
    memset(&un, 0, sizeof(un));
    un.sun_family = AF_UNIX;
    strcpy(un.sun_path, filename);

    if (connect(sock_fd, (struct sockaddr *) &un, sizeof(un)) < 0) {
        printf("connect socket failed\n");
        return -1;
    }

    char buffer[BUFFER_SIZE] = "你好,我是许磊";
    send(sock_fd, buffer, BUFFER_SIZE, 0);
    close(sock_fd);
    return 0;
}