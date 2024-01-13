//
// Created by xulei on 2018/6/16.
//

#include <stdio.h>
#include <printf.h>
#include <string.h>
#include "memset.h"

void TMemset() {
    // memset() 函数可以说是初始化内存的“万能函数”，通常为新申请的内存进行初始化工作。
    // 通常用来清空数组
    // 函数的功能是：将指针变量 s 所指向的前 n 字节的内存单元用一个“整数” c 替换，注意 c 是 int 型。s 是 void* 型的指针变量，所以它可以为任何类型的数据进行初始化。
    // memset() 的作用是在一段内存块中填充某个给定的值。因为它只能填充一个值，所以该函数的初始化为原始初始化，无法将变量初始化为程序中需要的数据。用memset初始化完后，后面程序中再向该内存空间中存放需要的数据。
    // memset 一般使用“0”初始化内存单元，而且通常是给数组或结构体进行初始化。一般的变量如 char、int、float、double 等类型的变量直接初始化即可，没有必要用 memset。如果用 memset 的话反而显得麻烦。
    // 当然，数组也可以直接进行初始化，但 memset 是对较大的数组或结构体进行清零初始化的最快方法，因为它是直接对内存进行操作的。

    char str[10];
    // 存在string.h文件中
    memset(str, '\0', sizeof(str));  //只能写sizeof(str), 不能写sizeof(p)
    for (int i = 0; i < 10; ++i) {
        printf("str %d=%d,地址=%p\n", i, str[i], &str[i]);
    }

    char *p = str;
    printf("p=%s,地址=%p,字节数=%lu\n", p, p,sizeof(p));
    printf("\n");
}