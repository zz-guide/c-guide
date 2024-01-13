//
// Created by xulei on 2019-02-07.
//

#include <printf.h>
#include "static.h"

#define AGEONE 12

static int count=10;        /* 全局变量 - static 是默认的 */

void testOne() {
//    int a;
//    printf("int 存储大小 : %lu \n", sizeof(int));//%lu 为 32 位无符号整数
//    printf("%p", &a);

//    const int AGE = 12;
//    AGE = 13;  //修改值会报错

//    printf("年龄：%d \n", AGE);
//    printf("年龄：%d", AGEONE);
//    while (count--) {
//        func1();
//    }

    printf("File :%s\n", __FILE__ );
    printf("Date :%s\n", __DATE__ );
    printf("Time :%s\n", __TIME__ );
    printf("Line :%d\n", __LINE__ );
    printf("ANSI :%d\n", __STDC__ );
}

void func1(void)
{
    /* 'thingy' 是 'func1' 的局部变量 - 只初始化一次
     * 每次调用函数 'func1' 'thingy' 值不会被重置。
     */
    static int thingy=5;

    thingy++;
    printf(" thingy 为 %d ， count 为 %d\n", thingy, count);
}