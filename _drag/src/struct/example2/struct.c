//
// Created by xulei on 2022/2/9.
//

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

/**
 * https://www.freesion.com/article/76931230996/
 * 1. __attribute__ ((__packed__))关键字
 * 结构体默认都是字节对齐的，加上__attribute__ ((__packed__))关键字，它可以做到让我们的结构体，按照紧凑排列的方式，占用内存。
 *
 *
 * 数据结构的对齐的问题。为了让我们的数据结构以最优的方式存储，处理，保证读写数据结构都一一对齐，我们往往采用3种方式：

    1.程序作者，手动对齐，将数据按从小到大的顺序排列，尽量凑齐。

    2.使用#pragma pack (n)来指定数据结构的对齐值。

    3.使用 __attribute__ ((packed)) ，让编译器取消结构在编译过程中的优化对齐,按照实际占用字节数进行对齐，这样子两边都需要使用 __attribute__ ((packed))取消优化对齐，就不会出现对齐的错位现象。

 */

// 编译器默认对齐
struct mysds1 {
    char c;
    int i;
};


// 不对齐
struct __attribute__ ((__packed__)) mysds {
    char c;
    int i;
};

// 自定义对齐
struct mysds2 {
    char c;
    int i;
} __attribute__ ((aligned(8)));

struct mysds3 {
    char c;
    int i;
} __attribute__ ((aligned(16))); // 对齐必须是2的幂

// 使用该属性可以使得变量或者结构体成员使用最小的对齐方式，即对变量是一字节对齐，对域（field）是位对齐。
struct mysds4 {
    char c;
    int i;
} __attribute__ ((packed));


void TStruct6() {
    printf("mysds sizeof=%lu\n", sizeof(struct mysds));
    printf("mysds1 sizeof=%lu\n", sizeof(struct mysds1));
    printf("mysds2 sizeof=%lu\n", sizeof(struct mysds2));
    printf("mysds3 sizeof=%lu\n", sizeof(struct mysds3));
    printf("mysds4 sizeof=%lu\n", sizeof(struct mysds4));
}