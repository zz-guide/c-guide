//
// Created by xulei on 2022/2/9.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

/**
 * 柔性数组：
 *  1.必须要声明在结构体的结尾。
    2.不占用结构体大小。
    3.结构体成员除了柔型数组成员，至少还有一个其他非柔性数组成员。
    4.柔性数组成员只作为一个符号地址存在，sizeof 返回的这种结构大小不包括柔性数组的内存。
    5.包含柔性数组成员的结构用malloc ()函数进行内存的动态分配，并且分配的内存应该大于结构体的大小，以适应柔性数组的预期大小。
    6.只需要释放一次内存

    7.指针形式的话，内存不在一块，无法一次释放

    strcpy和memcpy主要有以下3方面的区别。
　　1、复制的内容不同。strcpy只能复制字符串，而memcpy可以复制任意内容，例如字符数组、整型、结构体、类等。
　　　　企业中使用memcpy很平常，因为需要拷贝大量的结构体参数。
　　　　memcpy通常与memset函数配合使用。
　　2、复制的方法不同。strcpy不需要指定长度，它遇到被复制字符的串结束符"\0"才结束，所以容易溢出。memcpy则是根据其第3个参数决定复制的长度。
　　　　因此strcpy会复制字符串的结束符“\0”，而memcpy则不会复制。
　　3、用途不同。通常在复制字符串时用strcpy，而需要复制其他类型数据时则一般用memcpy
 *
 */

struct empty {};
struct empty1 {
    char a;
    char buf[]; // Flexible array member 'buf' not allowed in otherwise empty struct
};

struct student {
    int age;
    char *name;
    char buf[];
};

struct studentNew {
    int age;
    char *name;
};


void TStruct9() {
    // 1.柔性数组不占用结构体空间
    printf("empty sizeof=%lu \n", sizeof(struct empty));
    printf("empty1 sizeof=%lu \n", sizeof(struct empty1));

    // 2.柔性数组的空间地址
    struct student stu = {27, "许磊"};
    printf("stu大小=%lu, stu age = %d,name=%s,buf=%s\n", sizeof(stu), stu.age, stu.name, stu.buf);
    printf("stu 地址=%p,age地址=%p,name地址=%p, buf地址=%p\n", &stu, &stu.age, stu.name, stu.buf);
    printf("\n");
    // 3.包含柔性数组成员的结构体，分配内存必须分配至少结构体大小的内存，不能后期分配
    struct student *stu1 = (struct student *)malloc(sizeof(struct student) + sizeof(char) * 5);
    char szInfo[] = "hello";
    printf("szInfo=%s,地址=%p\n", szInfo, szInfo);
    memcpy(stu1->buf,szInfo, sizeof(szInfo));
    printf("stu1->buf=%s,地址=%p,%p\n", stu1->buf, stu1->buf, szInfo);
    stu1->buf[0] = 'c';
    printf("stu1->buf=%s,地址=%p,%p\n", stu1->buf, stu1->buf, szInfo);
    printf("szInfo=%s,地址=%p\n", szInfo, szInfo);

    // 4.char[]和char * 形式都可以修改字符串，但是字符串内存地址不一样，一个是常量区，一个是栈或者堆
    printf("\n");
    char *stu2 = "sss";
    printf("stu2=%s,地址=%p\n", stu2, stu2);
    stu2 = "cxcxc";
    printf("stu2=%s,地址=%p\n", stu2, stu2);
    printf("\n");

    // 6. 数组不指定长度
//    int a[]; // 不指定长度的话必须初始化
    int a[] = {1,2,3};
    printf("a[]不指定长度 sizeof=%lu,地址=%p\n", sizeof(a), a);
}