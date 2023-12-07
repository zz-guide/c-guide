//
// Created by xulei on 2022/2/14.
//

#include "thread.h"

// 线程处理函数
void *pthreadFunction(void *arg) {
    int *p = (int *) arg;//线程参数
    printf("child thread - 线程ID LWP:%x\n", (unsigned int) pthread_self());//获得线程ID
    printf("child thread - 线程参数：%d\n", *p);//参数

    //sleep(1);
    return NULL;
}

void TPthread() {
    pthread_t tid;//用来获取线程ID
    int num = 100;//线程参数
    int nReturnValue;//创建线程返回值
    //创建线程，成功返回0，失败返回错误码
    //1、创建线程，2、线程号填到tid,3、返回函数调用
    if (!(nReturnValue = pthread_create(&tid, NULL, pthreadFunction, (void *) &num))) {
        sleep(1);//主线程等待1S，让子线程运行起来
    } else {
        fprintf(stderr, "pthread_create失败：%s\n", strerror(nReturnValue));
        exit(1);
    }
    printf("main thread - 主控线程ID LWP:%x\n", (unsigned int) pthread_self());//线程ID
    printf("main thread - 子线程ID LWP:%x\n", (unsigned int) tid);//线程ID

    sleep(3);//保证子线程退出
}