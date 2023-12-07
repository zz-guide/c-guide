//
// Created by xulei on 2022/2/14.
//

#include "zoombie.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

/**
 *  僵尸进程
    进程在完成工作后应被销毁，但有时这些进程会进入僵尸状态，占用系统的资源，成为僵尸进程。

    僵尸进程产生原因
    给进程设置僵尸状态的目的是维护子进程的信息，以便父进程在以后某个时间获取。这些信息包括子进程的进程ID、终止状态以及资源利用信息(CPU时间，内存使用量等等)。如果一个进程终止，而该进程有子进程处于僵尸状态，那么它的所有僵尸子进程的父进程ID将被重置为1（init进程）。继承这些子进程的init进程将清理它们(init进程将wait它们，从而去除僵尸状态)。

    避免僵尸进程
    避免产生僵尸进程方法：

    fork()两次并杀死其父进程，使其变成孤儿进程，从而移交init处理
    在fork()后调用wait()/waitpid()函数主动取得子进程的退出状态
    wait()
    #include <sys/wait.h>
    pid_t wait(int *statloc);

    返回：
	成功：返回终止的子进程pid
	失败：-1
    调用此函数时如果已有子进程终止，那么子进程终止时传递的返回值将保存在该函数参数所指内存空间，但其中还包含其他信息，需要使用以下宏进行分离：

    WIFEXITED 子进程正常终止时返回true
    WEXITSTSTUS 返回子进程的返回值
    宏使用：在调用wait()函数后，编写如下代码

    if(WIFEXITED(status)) { //是否是正常终止
        puts("Normal termination!");
        printf("Child pass num: %d", WEXITSTATUS(status));	//子进程返回值
    }
    调用wait()函数时，如果没有已终止的子进程，那么程序将阻塞直至有子进程终止

    waitpid()
    #include <sys/wait.h>
    pid_t waitpid(pid_t pid, int *statloc, int options);

    返回：
        成功：返回终止的子进程pid（或0）
        失败：-1
    pid：等待终止的目标子进程pid，若传递-1,则与wait()函数相同，可等待任意子进程终止
    statloc：保存子进程的返回值
    options：传递头文件sys/wait.h中声明的常量WNOHANG，即使无终止的子进程也不会进入阻塞状态，而是返回0并退出函数

 *
 */

void read_childproc(int sig)
{
    int status;
    pid_t id = waitpid(-1, &status, WNOHANG);

    if(WIFEXITED(status)) {
        printf("Remove proc id: %d \n", id);
        printf("Child send: %d \n", WEXITSTATUS(status));
    }
}

void TZoombie()
{
    pid_t pid;
    struct sigaction act;
    act.sa_handler = read_childproc;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    sigaction(SIGCHLD, &act, 0);

    pid = fork();
    if(pid == 0) {
        //子进程执行区域
        puts("Hi! I'm child process");
        sleep(10);
        return 12;
    } else {
        //父进程执行区域
        printf("Child proc id: %d \n", pid);
        //再新开一个子进程
        pid = fork();
        if(pid == 0) {
            //另一个子进程执行区域
            puts("Hi! I'm child process");
            sleep(10);
            return 24;
        } else {
            //父进程执行区域
            int i;
            printf("Child proc id: %d \n", pid);
            for(i = 0; i < 5; i++) {
                puts("wait...");
                sleep(5);
            }
        }
    }

    return 0;
}