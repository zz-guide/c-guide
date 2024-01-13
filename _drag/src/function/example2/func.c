//
// Created by xulei on 2022/2/10.
//

#include "func.h"
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return a >= b ? a : b;
}

// 数组不能作为函数的返回值类型

int *pointerFunc(int a, int b) {
    // 函数返回指针方法1：使用static修饰
    // static修饰的变量声明的时候不能直接赋值变量，必须先声明，后赋值
    static int max;
    max = a >= b ? a : b;
    //    C 语言不支持在调用函数时返回局部变量的地址，除非定义局部变量为 static 变量
    // 函数运行结束后会销毁在它内部定义的所有局部数据，包括局部变量、局部数组和形式参数，函数返回的指针请尽量不要指向这些数据，C语言没有任何机制来保证这些数据会一直有效，它们在后续使用过程中可能会引发运行时错误
    return &max;
}

int *pointerFunc1(int a, int b) {
    // 函数返回指针方法1：动态分配到堆上，使用完毕释放
    int *max = (int *) malloc(sizeof(int));
    *max = a >= b ? a : b;
    printf("max 地址=%p\n", max);
    return max;
}

int pointerFunc2(int a, int b, int *res) {
    // 函数返回指针方法1：传参的时候把指针传进来进行赋值
    *res = a >= b ? a : b;
    printf("max 地址=%p\n", res);
    return 0;
}

void TPointerFunc() {
    // 指针函数，函数的返回值是一个指针,本质是函数

    int *p = pointerFunc(3, 4);
    printf("p = %d\n", *p);

    int *p1 = pointerFunc1(3, 4);
    printf("p1 = %d,地址=%p\n", *p1, p1);
    free(p1);
    p1 = NULL;

    int res = 0;
    pointerFunc2(3, 4, &res);
    printf("res = %d,地址=%p\n", res, &res);
}


void TFuncPointer() {
    // 函数指针：一个指针变量指向函数,本质是变量
    int (*p)(int, int);
    // 函数名也是地址
    printf("max地址=%p\n", max);
    p = &max;
    int (*p1)(int, int) = &max;
    int res = p(2, 3);
    int res1 = p1(2, 3);
    printf("res = %d\n", res);
    printf("res1 = %d\n", res1);
}