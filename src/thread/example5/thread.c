//
// Created by xulei on 2022/2/14.
//


/**
 * 其实在Linux中，新建的线程并不是在原先的进程中，而是系统通过一个系统调用clone()。
 * 该系统调用copy了一个和原先进程完全一样的进程，并在这个进程中执行线程函数。
 * 不过这个copy过程和fork不一样。 copy后的进程和原先的进程共享了所有的变量，
 * 运行环境。这样，原先进程中的变量变动在copy后的进程中便能体现出来。
 */

#include <stdbool.h>
#include "thread.h"

#define PNUM 100000
pthread_t th[5];

// volatile 并不能保证原子性
//volatile int a = 0;
int a = 0;
bool isLock = true;

// 1.通过互斥锁的方式同步数据,读写互斥
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
// 2.读写锁，写互斥
pthread_rwlock_t rwlock;

typedef void *(*THREAD_FUNC)(void *);

void *pthreadFunc1(void *arg) {
    if (arg != NULL) {
        int *p = (int *) arg;
        printf("thread1 参数=%d, 地址=%p\n", *p, p);
    }

//    printf("thread1 threadId=%lu,pid=%d \n", (unsigned long) pthread_self(), getpid());

    for (int i = 0; i < PNUM; ++i) {
        // 加锁解锁
        if (isLock) {
            pthread_mutex_lock(&mutex);
        }

        a = a + 1;
        printf("thread1 a=%d\n", a);
        if (isLock) {
            pthread_mutex_unlock(&mutex);
        }

    }

    printf("thread1 finish: a=%d\n", a);
    return NULL;
}

void *pthreadFunc2(void *arg) {
    if (arg != NULL) {
        int *p = (int *) arg;
        printf("thread2 参数=%d, 地址=%p\n", *p, p);
    }

//    printf("thread2 threadId=%lu,pid=%d \n", (unsigned long) pthread_self(), getpid());

    for (int i = 0; i < PNUM; ++i) {
        // 加锁解锁
        if (isLock) {
            pthread_mutex_lock(&mutex);
        }

        a = a + 1;
        printf("thread2 a=%d\n", a);
        if (isLock) {
            pthread_mutex_unlock(&mutex);
        }
    }

    printf("thread2 finish: a=%d\n", a);
    return NULL;
}

void *pthreadFuncRead(void *args) {
    while (1) {
        pthread_rwlock_wrlock(&rwlock);
        printf("read:%lu,a=%d\n", (unsigned long) pthread_self(), a);
        pthread_rwlock_unlock(&rwlock);
        sleep(1);
    }
}

void *pthreadFuncWrite(void *args) {
    int t;
    while (1) {
        pthread_rwlock_wrlock(&rwlock);//写锁，请求不到写锁则阻塞
        t = a;
        usleep(100);
        printf("write---:%lu   :a=%d - ++a=%d\n", (unsigned long) pthread_self(), t, ++a);
        pthread_rwlock_unlock(&rwlock);
        sleep(1);
    }
}

void CreateThread(int i, THREAD_FUNC tf, int param) {
    printf("\n");
    int status = pthread_create(&th[i], NULL, tf, &param);
    // 发现不加sleep，有时候参数没有传入线程函数
//    sleep(1);
//    printf("tf =%p, status=%d \n", tf, status);
    if (status != 0) {
        fprintf(stderr, "thread %s\n", strerror(status));
    }

//    pthread_join(th, NULL);
//    pthread_detach(th);
}

void ttt() {
    if (isLock) {
        pthread_mutex_init(&mutex, NULL);
    }

    CreateThread(0, pthreadFunc1, 3);
    CreateThread(1, pthreadFunc2, 4);
    pthread_join(th[0], NULL);
    printf("th 000000\n");
    pthread_join(th[1], NULL);
    printf("th 11111111\n");
    // 释放锁
    if (isLock) {
        pthread_mutex_destroy(&mutex);
    }

}

void TPthread5() {
    printf("开始执行, pthreadFunc1=%p, pthreadFunc2=%p\n", pthreadFunc1, pthreadFunc2);
    ttt();
    getchar();
    printf("a = %d\n", a);
}