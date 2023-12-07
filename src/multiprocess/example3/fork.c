//
// Created by xulei on 2022/2/14.
//

#include "fork.h"
#include<stdio.h>
#include<unistd.h>

/**
 * fork函数
 * 1.fork()函数调用一次，返回两次，有三种返回值
 * 1.在父进程中，fork返回新创建子进程的进程ID；
 * 2.在子进程中，fork返回0；
 * 3.如果出现错误，fork返回一个负值；
 * 2.fork函数创建的子进程将会获得其父进程（fork函数调用者）的数据段、堆和栈的副本，并与其父进程共享代码段
 *
 *  进程的状态：
 *  可运行状态（TASK_RUNNING，简称R）
    可中断的睡眠状态（TASK_INTERRUPTIBLE，简称S）
    不可中断的睡眠状态（TASK_UNINTERRUPTIBLE，简称D）
    暂停或追踪状态（TASK_STOPPED/TASK_TRACED，简称T）
    僵尸状态（TASK_DEAD-EXIT_ZOMBIE，简称Z）
    退出状态（TASK_DEAD-EXIT_DEAD，简称X）
 */


int gval = 10;


int TFork(){
    pid_t pid;
    int lval = 25;
    gval++;

    pid = fork();
    //子进程开始
    if(pid == 0) {
        gval += 1;
        lval += 1;
        printf("child pid: %d\n", getpid());
    } else {
        gval -= 1;
        lval -= 1;
        printf("father 子进程pid=%d,父进程pid=%d\n", pid, getpid());
    }

    if(pid == 0) {
        printf("Child Proc: [%d, %d] \n", gval, lval);
    } else {
        printf("Parent Proc: [%d, %d] \n", gval, lval);
    }

    return 0;
}