//
// Created by xulei on 2022/2/14.
//
#include "thread.h"
int main() {
    printf("main PID=%d\n", getpid());
    TPthread5();
    pthread_exit(NULL);
    return 0;
}