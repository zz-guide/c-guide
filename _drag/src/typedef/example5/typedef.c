//
// Created by xulei on 2021/11/28.
//

#include "./typedef.h"
#include<stdio.h>

// typedef 数组

/**
 * 结论：
 *  1.*和名字被小括号括起来，认为先是一个指针，比如(*ptr)
 *  2.*和名字没被括号括起来，认为是其他，比如*ptr
 */

// 函数指针
typedef void (*PTR_TO_ARRAY)(void);

void test1(void) {
    printf("我是void参数函数!!!\n");
}

void test2() {
    printf("我是无参函数 !!!\n");
}

// 函数指针
typedef int *(*PTR_TO_ARRAY1)(int);

int *PointerFunc123(int a){
    static int temp = 1;
    temp += a;
    printf("指针函数PointerFunc123 形参a=%d,temp=%d\n", a, temp);
    return &temp;
}

int *PointerFunc124(int a){
    static int temp = 2;
    temp += a;
    printf("指针函数PointerFunc124 形参a=%d,temp=%d\n", a, temp);
    return &temp;
}

int *PointerFunc125(int a){
    static int temp = 3;
    temp += a;
    printf("指针函数PointerFunc125 形参a=%d,temp=%d\n", a, temp);
    return &temp;
}

void TTypedef5() {
    // 指针数组，数组的成员都是指针类型的
    PTR_TO_ARRAY1 array[3] = {PointerFunc123, PointerFunc124, PointerFunc125};
    for (int i = 0; i < 3; ++i) {
        // 对于函数来说，array[i]等价于*array[i]
        printf(" %i 地址=%p\n", i, (array[i])(i));
        printf(" %i 地址=%p\n", i, (*array[i])(i));
        printf("\n");
    }
}