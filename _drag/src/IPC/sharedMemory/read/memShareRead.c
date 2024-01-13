//
// Created by xulei on 2022/3/5.
//

#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFSIZE 1024
#define IPCKEY 0x344378

int main(int args, char *argv[]) {
    // 创建key值
    key_t key;
    if ((key = ftok("./", 1)) == -1) {
        perror("ftok error.");
        return -1;
    }

    printf("ftok ok ,key = %d\n", key);
    // 查看系统共享内存
    printf("start-ipcs------------------------------------------\n");
    system("ipcs -m");
    printf("end-ipcs--------------------------------------------\n");

    // 打开共享内存，已存在就读取，不存在就创建
    int shmid;
    if ((shmid = shmget(key, BUFFSIZE, IPC_CREAT|0666)) < 0) {
        perror("shmget error.");
        return -1;
    }

    printf("Open shared-memory success, with shmid: %d\n", shmid);

    // 映射,将进程连接到共享存储段地址空间中
    char *shmadd;
    if ((shmadd = shmat(shmid, NULL, 0)) < 0) {
        perror("shmat error.");
        return -1;
    }

    // 读取共享内存中的数据
    printf("read data from shared-memory\n");
    printf("%s\n", shmadd);

    // 分离共享内存和当前进程
    if (shmdt(shmadd) < 0) {
        perror("卸载 shmdt error.");
        exit(1);
    } else {
        printf("Delete shared-memory\n");
    }

    // 删除共享内存
    shmctl(shmid, IPC_RMID, NULL);

    // 查看系统共享内存
    printf("start-ipcs------------------------------------------\n");
    system("ipcs -m");
    printf("end-ipcs--------------------------------------------\n");

    return 0;
}