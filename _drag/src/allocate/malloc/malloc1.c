//
// Created by xulei on 2021/11/28.
//

#include "malloc1.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * 结论：
 * 1.free同一个指针不能调用两次，会报错：error for object 0x7fa3bbe04160: pointer being freed was not allocated
 * 2.free的同时别忘了把变量设置为NULL,否则还是能读到的，但是不安全的，free不会修改变量的指向
 * 3.malloc(size) 如果size为0, 此行为是未定义的, 会发生未知错误, 取决于编译器
 * 4.malloc(size) 实际分配的并不等于size尺寸内存，这个内存块的大小还受到（1）Alignment 对齐 == 2 * sizeof(size_t) ，（2）overhead 信息， 这两方面的共同约束。
 *
 *  //①内存需要分配，但也是需要初始化的，并且使用完毕需要释放，否则会发生内存泄漏（即内存未回收）
    //②静态存储区内存分配，编译期间就一直存在，无须手动分配， 内存在程序编译的时候就已经分配好，这块内存在程序的整个运行期间都存在。例如全局变量，static变量
    //③栈中分配内存，在执行函数时，函数内局部变量的存储单元都可以在栈上创建，函数执行结束时，这些存储但愿自动被释放。效率很高，但是分配的内存容量比较有限
    //④堆中分配内存，在堆上分配也称为动态内存分配：程序在运行的时候用malloc等函数申请任意多少的内存，
    // 程序员自己负责在何时用free释放内存。动态内存分配的生存期由我们自己决定，使用非常灵活，但是问题相对也比较多；
    // 注意：//如果没有释放的话，很容易就会造成内存溢出，因为堆中的内存块是全局的，因此不会因为函数的调用而结束
 */

void TMalloc1() {
    // 1. 初始化一个指针变量为NULL,发现NUL指针变量都指向一个地址
    int *p = NULL;
    float *p1 = NULL;
    printf("p= ,地址=%p\n", p);
    printf("p1= ,地址=%p\n", p1);
    // NULL指针必须动态分配内存，不能直接赋值
//    int a = 50;
//    p = &a;
//    printf("分配之后 p=%d ,地址=%p\n", *p, p);

    // 2.malloc只负责分配内存，不负责初始化，值是随机的，分配的是堆空间
    p = (int*)malloc(sizeof(int));
    // 分配内存成功以后，int值变成为0
    if (p == NULL) {
        printf("分配内存失败\n");
        return;
    } else {
        printf("分配成功 p=%d,地址=%p\n", *p, p);
    }

    *p = 50;
    printf("分配之后 p=%d ,地址=%p\n", *p, p);

    free(p);
    // free之后需要把变量置为NULL,防止误用
    p = NULL;
    printf("p地址=%p\n", p);
    // 有错误不会打印
    printf("分配之后 p=%d ,地址=%p\n", *p, p);
}

void TMalloc2(){
    char *p = NULL;
    p = (char*)malloc(2);
    if (p == NULL) {
        printf("分配内存失败");
        return;
    } else {
        printf("分配成功 p=%c,地址=%p\n", *p, p);
    }

    p[0]= 'a';
    p[1]= 'b';
    p[2]= 'c';
    p[66]= '\0';
    printf("p = %s, %p, %lu字节\n", p, p, sizeof(p));

    free(p);
    p = NULL;
    printf("p地址=%p\n", p);
}

void TMalloc3(){
    char *a =NULL;
    printf("a sizeof=%lu\n", sizeof(a));

    a = (char *)malloc(sizeof(char) * 10);
    a[3]='h';
    a[5]='e';
    printf("a sizeof=%lu,a=%s\n", sizeof(a), a);

    char *a1 = (char *)calloc(10, sizeof(char));
    a1[0]='h';
    a1[3]='e';
    a1[10-1]= 255;
    printf("a1 sizeof=%lu,a1=%s\n", sizeof(a1), a1);
}