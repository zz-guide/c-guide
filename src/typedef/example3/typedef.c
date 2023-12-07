//
// Created by xulei on 2021/11/28.
//

#include "./typedef.h"
#include<stdio.h>

// typedef 指针系列

// 变量指针
typedef int (*PointerInt);

// 数组指针,可以不指定长度
typedef int (*PointerToArray)[];

// 函数指针，指针指向函数
typedef int (*PointerToFunc)(int);

int Add(int a) {
    return a+1;
}

void TTypedef3() {
    // 指针变量
    int a = 2;
    PointerInt pointerInt = &a;
    printf("pointerInt=%d,地址=%p\n", *pointerInt, pointerInt);

    // 指针函数，当一个指针变量指向函数名时，可以直接使用，也可以解引用之后使用mp等价于(*mp)
    PointerToFunc pointerToFunc = Add;
    int res = pointerToFunc(3);
    int res1 = (*pointerToFunc)(3);
    printf("res=%d,pointerToFunc地址=%p, %p\n", res, pointerToFunc, Add);
    printf("res1=%d,pointerToFunc地址=%p, %p\n", res1, pointerToFunc, Add);

    // 指针数组
    int b[] = {1,2,3};
    PointerToArray pointerToArray = (PointerToArray) b; // 不指定长度是需要转化类型的，不同长度是不用类型
    printf("pointerToArray地址=%p, %p\n", pointerToArray, b);

}