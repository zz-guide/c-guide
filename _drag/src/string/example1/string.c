//
// Created by xulei on 2018/6/16.
//

#include <printf.h>
#include <string.h>
#include <stdio.h>

void TString() {
    char *str = "我";
    char str1[] = "We are csdn!";
    // 指针不能直接赋值，需要开辟内存空间才能使用
    char cpy[4];
    strcpy(cpy, str);
    printf("str = %s,地址=%p\n", str, &str);
    printf("cpy = %s,地址=%p\n", cpy, &cpy);
}