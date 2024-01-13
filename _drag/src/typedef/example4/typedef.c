//
// Created by xulei on 2021/11/28.
//

#include "./typedef.h"
#include<stdio.h>

// typedef 函数

// 常规函数起别名类型
typedef int FuncAlias(int);

int sum(int a) {
    return a + 1;
}

// 指针函数,函数返回值是一个指针
typedef int *FuncReturnPointer(int);

int *func1(int a) {
    static int res;
    res = a;
    return &res;
}

void TTypedef4() {
    // typedef简单定义函数类型, 需要用指针接收
    FuncAlias *funcAlias = sum;
    int res = funcAlias(2);
    printf("res=%d,地址=%p, %p\n", res, funcAlias, sum);

    // 指针函数
    FuncReturnPointer *funcReturnPointer = func1;

    int *v = funcReturnPointer(4);
    printf("v=%d,地址=%p, %p\n", *v, funcReturnPointer, func1);
}