//
// Created by xulei on 2018/6/16.
//

#include <printf.h>
#include <string.h>
#include <stdio.h>

static void temp(int a[]){
    // 函数参数如果是数组的话，函数内部使用sizeof实际上是获取的指针的大小
    printf("sizeof(a)=%lu,a长度=%lu\n",sizeof(a), sizeof(a) / sizeof(int));
}

void TString2() {
    // 字符串数组
    char *names[] = {"许磊", "张三", "李四"};
    printf("names 地址=%p, names[0]地址=%p\n", names, &names[0]);
    int len = sizeof(names) / sizeof(char *);
    for (int i = 0; i < len; i++) {
        printf("names[%d]=%s,地址=%p,字符串地址=%p\n", i, names[i], &names[i], names[i]);
    }

//    char *str = (char *)0x10b449f40;
//    printf("str = %s\n", str);

    // 数组长度
    int a[] = {1,2,3};
    printf("sizeof(a)=%lu,a长度=%lu\n",sizeof(a), sizeof(a) / sizeof(int));
    temp(a);
}