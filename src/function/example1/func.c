//
// Created by xulei on 2022/2/10.
//

#include "func.h"
#include <stdarg.h>
#include <stdio.h>

// 可变参数，需要提前预知参数个数,参数类型可以是不同的
void average1(int num, ...) {
    va_list vaList;
    /* 为 num 个参数初始化 valist */
    va_start(vaList, num);
    int a = va_arg(vaList, int);
    char *b = va_arg(vaList, char*);
    char c = va_arg(vaList, int);
    int d = va_arg(vaList, int);
    printf("a = %d\n", a);
    printf("b = %s\n", b);
    printf("c = %c\n", c);
    printf("d = %d\n", d);


    va_end(vaList);
}

// 函数指针的定义方式：函数返回值类型 (* 指针变量名) (函数参数列表);
// 指向函数的指针变量没有 ++ 和 -- 运算
int Max(int x, int y)  //定义Max函数
{
    return x >= y ? x : y;
}

void TScope(){
    int n = 22;  //编号①
    //由{ }包围的代码块
    {
        int n = 40;  //编号②
        printf("block n: %d\n", n);
    }
    printf("main n: %d\n", n);
}

void TFunc1(){
    // 1.可变参数
    // average1(4, 2,"哈哈",'c',5);

    // 2. 函数指针
//    int(*p)(int, int);
//    p = Max;
//    int c = (*p)(5, 10);  //通过函数指针调用Max函数
//    printf("c = %d\n", c);

    TScope();
}