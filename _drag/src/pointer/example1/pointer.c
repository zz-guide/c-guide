//
// Created by xulei on 2022/2/13.
//

#include "pointer.h"
#include <stdio.h>

void TPointer(){
    // 变量
    int a = 1;
    printf("a=%d,地址=%p\n", a, &a);
    // 指针
    int *b = &a;
    printf("b=%d,地址=%p,指向地址=%p\n", *b, &b, b);
    // 二级指针
    int **c = &b;
    printf("c=%d,地址=%p,指向地址=%p\n", **c, &c, c);
}