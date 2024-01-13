//
// Created by xulei on 2022/3/5.
//

#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

// 共享内存大小
#define BUFFSIZE 1024
#define IPCKEY 0x344378

int main(int argc, char *argv[]) {
    // 共享内存的key, 创建共享内存的key
    key_t key;
    if ((key = ftok("./", 1)) == -1) {
        perror("ftok error");
        return -1;
    }

    printf("ftok ok ,key = %d\n", key);
    // 共享内存的shmid, 创建共享内存
    int shmid;
    if ((shmid = shmget(key, BUFFSIZE, IPC_CREAT|0666)) < 0) {
        perror("shmget error.");
        exit(-1);
    }

    printf("Create shared-memory success, with shmid: %d\n", shmid);

    // 映射, 根据实际类型进行转换
    char *shmadd;
    if ((shmadd = (char *)shmat(shmid, NULL, 0)) < 0) {
        perror("shmat error.");
        exit(-1);
    }

    // 拷贝共享数据到共享内存
    printf("copy data to shared-memory\n");
    bzero(shmadd, BUFFSIZE);

    char *msg = "hello world";
    strcpy(shmadd, msg);
    printf("copy data to shared-memory success, with msg: %s\n", msg);
}