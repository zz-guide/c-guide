//
// Created by xulei on 2022/2/14.
//

#include "thread.h"

//线程函数
void* pthreadFunction(void* arg){
   return NULL;
}

/**
 * pthread_cancel
 */

void TPthread4() {
    pthread_t tid;
    pthread_attr_t attr;
    int err;
    //初始化线程属性
    pthread_attr_init(&attr);
    //线程属性有分离和非分离属性PTHREAD_CREATE_JOINABLE
    pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
    pthread_create(&tid,&attr,pthreadFunction,NULL);
    err = pthread_join(tid,NULL);
    while(1){
        if(err){
            fprintf(stderr,"pthread_join %s",strerror(err));
            printf("主线程已经开庭时退出了\n");
            sleep(10);//把这行注释掉，子线程变成僵尸线程
            pthread_exit((void*)-1);//这样主线程退出，不影响子线程的运行,但是如果子线程没有退出，将会变成僵尸线程
        }
    }
}