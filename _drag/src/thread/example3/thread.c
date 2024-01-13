//
// Created by xulei on 2022/2/14.
//

#include "thread.h"

//线程函数
void *pthreadFunc(void *args) {
    int n = 3;
    while (n--) {
        printf("线程函数计数：%d\n", n);
        sleep(1);
    }
    static int res;
    res = 12;
    return &res;
}

/**
 * 1.int pthread_detach(pthread_t thread);    成功：0；失败：错误号
 * 线程运行结束后会自动释放所有资源。线程分离，分离后不用在使用pthread_join等待线程退出才能释放资源，分离后线程退出系统自动释放资源
 * 2.或者通过pthred_create的第二个参数指定
 *
 */

void TPthread3() {

    /**
     * pthread_join多次： 主线程会等待子线程执行完毕，相当于同步
     * 线程执行完毕之后，pthread_join会报错
        main PID=86472
        线程函数计数：2
        线程函数计数：1
        线程函数计数：0
        err = 0
        thread exit code 12
        err = 3
        thread No such process
        err = 3
        thread No such process
        err = 3
        thread No such process
        thread No such process
        err = 3
        thread No such process
        err = 3

        Process finished with exit code 143 (interrupted by signal 15: SIGTERM)

     */

    /**
     * 开启pthread_detach(tid); 主线程不会等待子线程执行完毕，相当于异步
     * 此时pthread_join会报错
        thread Invalid argument
        main PID=86507
        err = 22
        线程函数计数：2
        thread Invalid argument
        err = 22
        线程函数计数：1
        thread Invalid argument
        err = 22
        线程函数计数：0
        err = 22
        thread Invalid argument
        err = 3
        thread No such process
        thread No such process
        err = 3
        err = 3
        thread No such process
        err = 3
        thread No such process

        Process finished with exit code 143 (interrupted by signal 15: SIGTERM)

     */

    pthread_t tid;
    void *res = NULL;

    int err;
    pthread_create(&tid, NULL, pthreadFunc, NULL);
    pthread_detach(tid);

    while (1) {
        err = pthread_join(tid, &res);
        printf("err = %d\n", err);
        if (err)
            fprintf(stderr, "thread %s\n", strerror(err));
        else
            fprintf(stderr, "thread exit code %d\n", *(int *)res);

        sleep(1);
    }
}