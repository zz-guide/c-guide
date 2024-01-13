//
// Created by xulei on 2021/11/28.
//

#include "calloc.h"
#include <stdlib.h>
#include <stdio.h>

void TCalloc1(){
    // 1.与malloc不同的是，会初始化内存为0
    // 2.如果size与num有一个或都为0, 此行为是未定义的, 会发生未知错误, 取决于编译器
    int *p = NULL;
    int num = 3;
    p = (int*)calloc(num, sizeof(int));
    if (p == NULL) {
        printf("分配内存失败");
        return;
    } else {
        printf("分配成功 p=%c,地址=%p\n", *p, p);
    }

    p[0] = 5;
    p[1] = 15;
    printf("p=%d,地址=%p,字节数=%lu\n", *p, p, sizeof(p)); // 指针变量通常是8字节

    // p = &p[0]
    for (int i=0;i<10;i++)
    {
        printf("p %d=%d,地址=%p\n",i,p[i],&p[i]);
    }
}