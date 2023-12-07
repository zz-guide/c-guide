//
// Created by xulei on 2022/2/14.
//

#include "time.h"
#include <time.h>
#include <stdio.h>
#include <unistd.h>

static void TClock();

void TTime() {
    // 1.获取当前时间戳
//    time_t timeStamp = time(NULL);  // NULl代表从1970-01-01 00:00:00到现在的秒数
//    printf("当前时间戳 = %ld\n", timeStamp);

    // 2.clock函数
//    TClock();

    // 3.asctime函数

//    struct tm t;//更多情况下是通过localtime函数及gmtime函数获得tm结构
//    t.tm_sec    = 10;
//    t.tm_min    = 10;
//    t.tm_hour   = 6;
//    t.tm_mday   = 25;
//    t.tm_mon    = 2;
//    t.tm_year   = 89;
//    t.tm_wday   = 6;

//    printf("%s\n",asctime(&t));// 函数功能:将结构struct tm * ptr所表示的时间以字符串表示,返回的时间字符串格式为：星期,月,日,小时:分:秒,年

    // 4.localtime函数
    //    time_t timer;
//    time(&timer);
//    struct tm *Now = localtime(&timer);
//    printf("当前的本地时间和日期：%s", asctime(Now));

//    time_t curtime;
//    time(&curtime);
//    printf("当前时间 = %s", ctime(&curtime)); // 将日历时间参数timer转换为一个表示本地当前时间的字符串,回字符串格式：星期,月,日,小时:分:秒,年

    time_t rawtime;
    struct tm *info;
    char buffer[80];

    time(&rawtime);

    info = localtime(&rawtime);

    strftime(buffer, 80, "%Y-%m-%e %H:%M:%S", info);//以年月日_时分秒的形式表示当前时间
    printf("%s\n", buffer);

}

static void TClock() {
    clock_t start_t, finish_t;
    double total_t = 0;
    int i = 0;
    start_t = clock();
    for (; i < 2; ++i) {
        printf("睡眠2s\n");
        sleep(2);
    }
    finish_t = clock();
    total_t = (double) (finish_t - start_t) / CLOCKS_PER_SEC;//将时间转换为秒

    printf("CPU 占用的总时间：%f\n", total_t);
}