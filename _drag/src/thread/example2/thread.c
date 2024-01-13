//
// Created by xulei on 2022/2/14.
//

#include "thread.h"

//线程函数
void *ThreadFunc1(void *args) {
    printf("线程1 运行, pid=%d, thread id=%lu\n", getpid(), (unsigned long) pthread_self());
    sleep(3);
    static int res;
    res = 12;
    return &res;
}

void *ThreadFunc2(void *args) {
    printf("线程2 运行, pid=%d, thread id=%lu\n", getpid(), (unsigned long) pthread_self());
    sleep(3);
    static int res;
    res = 12;
    pthread_exit(&res);
    printf("********此语句不会被线程执行*********");//此语句不会被线程执行
}

void *ThreadFunc3(void *args) {
    printf("线程3 运行, pid=%d, thread id=%lu\n", getpid(), (unsigned long) pthread_self());
    while (1) {
        printf("线程3 2秒输出一次\n");
        sleep(1);
    }
}

/**
 *  1.int pthread_join(pthread_t thread, void **retval);
 *  以阻塞的方式等待thread指定的线程结束。当函数返回时，被等待线程的资源被收回。
 *  thread: 线程标识符，即线程ID，标识唯一线程。
 *  retval: 用户定义的指针，用来存储被等待线程的返回值。（二级指针）
 *
 *  2.线程结束的3种方式：
 *  线程将指定函数体中的代码执行完后自行结束；（函数直接return）
    线程执行过程中，被同一进程中的其它线程（包括主线程）强制终止；(main函数运行不等待)
    线程执行过程中，遇到 pthread_exit() 函数结束执行。
    注意，默认属性的线程执行结束后并不会立即释放占用的资源，直到整个进程执行结束，所有线程的资源以及整个进程占用的资源才会被操作系统回收。
    实现线程资源及时回收的常用方法有两种，一种是修改线程属性，另一种是在另一个线程中调用 pthread_join() 函数，我们会在后续章节中给您详细介绍这两种方法。

    3.void pthread_exit(void *retval);
    retval 是 void* 类型的指针，可以指向任何类型的数据，它指向的数据将作为线程退出时的返回值。如果线程不需要返回任何数据，将 retval 参数置为 NULL 即可。
    注意，retval 指针不能指向函数内部的局部数据（比如局部变量）。换句话说，pthread_exit() 函数不能返回一个指向局部数据的指针，否则很可能使程序运行结果出错甚至崩溃。

    4.pthread_exit()等价于return

    5.int pthread_cancel(pthread_t thread)
    pthread_cancel调用并不等待线程终止，它只提出请求。线程在取消请求(pthread_cancel)发出后会继续运行，
    直到到达某个取消点(CancellationPoint)。取消点是线程检查是否被取消并按照请求进行动作的一个位置.

    与取消由有关的函数：
    int pthread_setcancelstate(int state,   int *oldstate)
    设置本线程对Cancel信号的反应，state有两种值：PTHREAD_CANCEL_ENABLE（缺省）和PTHREAD_CANCEL_DISABLE，
    分别表示收到信号后设为CANCLED状态和忽略CANCEL信号继续运行；old_state如果不为NULL则存入原来的Cancel状态以便恢复。

    int pthread_setcanceltype(int type, int *oldtype)
    设置本线程取消动作的执行时机，type由两种取值：PTHREAD_CANCEL_DEFFERED和PTHREAD_CANCEL_ASYCHRONOUS，
    仅当Cancel状态为Enable时有效，分别表示收到信号后继续运行至下一个取消点再退出和立即执行取消动作（退出）；
    oldtype如果不为NULL则存入运来的取消动作类型值。

    https://www.cnblogs.com/lijunamneg/archive/2013/01/25/2877211.html
    void pthread_testcancel(void)
    是说pthread_testcancel在不包含取消点，但是又需要取消点的地方创建一个取消点，以便在一个没有包含取消点的执行代码线程中响应取消请求.
    线程取消功能处于启用状态且取消状态设置为延迟状态时，pthread_testcancel()函数有效。
    如果在取消功能处处于禁用状态下调用pthread_testcancel()，则该函数不起作用。
    请务必仅在线程取消线程操作安全的序列中插入pthread_testcancel()。除通过pthread_testcancel()调用以编程方式建立的取消点意外，pthread标准还指定了几个取消点。测试退出点,就是测试cancel信号.






 */

void TPthread1() {
    pthread_t tid;

//    pthread_create(&tid, NULL, ThreadFunc1, NULL);
//    void *res = NULL;
//    pthread_join(tid, &res);
//    printf("线程1线程函数退出返回值：%d\n", *(int *) res);
//
//    pthread_create(&tid, NULL, ThreadFunc2, NULL);
//    void *res1 = NULL;
//    pthread_join(tid, &res1);
//    printf("线程2线程函数退出返回值：%d\n", *(int *) res1);

    pthread_create(&tid,NULL,ThreadFunc3,NULL);
    void *res2 = NULL;
    sleep(4);
    printf("线程已经提出取消请求\n");
    pthread_cancel(tid);
    pthread_join(tid,&res2);
    printf("线程3线程函数退出返回值：%d\n",*(int *)res2);

}