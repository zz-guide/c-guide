//
// Created by xulei on 2022/2/10.
//

#include <stdio.h>
#include <assert.h>
#include "array.h"

void TArrayPointer() {
    // 数组指针，是一个指针,指向数组
    int a[3] = {1, 2, 3};
    int b[2][3] = {1, 2, 3, 4, 5, 6};

    // 等价
    int *p1 = a;
    int(*p2)[3] = b;    // 多维数组的指针会带[]

    // 指针可以比较大小
    printf("a地址=%p, p1地址=%p, 相等=%d\n", a, p1, a == p1);
    printf("b地址=%p, p2地址=%p, 相等=%d\n", b, p2, b == p2);

    // 这里的数组指针指向的是一维数组，主要是&a和a要分清：
    //1.c是数组名，是数组首元素地址，+1表示地址值加上一个int类型的大小，如果a的值是0x00000001，加1操作后变为0x00000005。*(a + 1) = a[1]。
    //2.&c是数组的指针，其类型为int(*)[5]（就是前面提到的数组指针），其加1时，系统会认为是数组首地址加上整个数组的偏移（5个int型变量），值为数组c尾元素后一个元素的地址。
    int c[5] = {1, 2, 3, 4, 5};
    printf("c[0]值=%d,地址=%p, c首地址=%p\n", c[0], &c[0], c);

    // 不加&相当于在数组第一个元素处位置进行偏移
    int *p4 = (int *) (c + 1);
    printf("c[1]地址=%p, p4值=%d,地址=%p\n", &c[1], *p4, p4);

    // 加了&相当于在数组的末尾处进行偏移
    int *p3 = (int *) (&c + 1);
    printf("c[4]地址=%p, p3值=%d,地址=%p\n", &c[4], *p3, p3);
}

void TPointerArray() {
    // 指针数组，数组的元素都是指针

    // 局部变量，栈内，发现地址从大到小
    int a = 3;
    int b = 4;
    int c = 4;
    printf("a=%d,地址=%p\n", a, &a);
    printf("b=%d,地址=%p\n", b, &b);
    printf("c=%d,地址=%p\n", c, &c);

    // 指针数组，以下三种写法等价，都是指针数组，内部都是8个字节，固定大小
    // int *(p[3])
    // int *(p1)[3]
    // int *p2[3]
    int *(p[3]) = {&a, &b, &c};
    // p 等价于 &p，但是指针计算的时候有区别，要注意
    printf("p地址=%p, %p\n", p, &p);
    // 对于指针变量，加&就是取自身变量的地址，不加就是取内部存的地址
    printf("p[0]=%d,地址=%p, %p\n", *p[0], &p[0], p[0]);
    printf("p[1]=%d,地址=%p, %p\n", *p[1], &p[1], p[1]);
    printf("p[2]=%d,地址=%p, %p\n", *p[2], &p[2], p[2]);
    printf("\n");
    int *(p1)[3] = {&a, &b, &c};
    printf("p1地址=%p\n", p1);
    printf("p1[0]=%d,地址=%p, %p\n", *p1[0], &p1[0], p1[0]);
    printf("p1[1]=%d,地址=%p, %p\n", *p1[1], &p1[1], p1[1]);
    printf("p1[2]=%d,地址=%p, %p\n", *p1[2], &p1[2], p1[2]);
    printf("\n");
    int *p2[3] = {&a, &b, &c};
    printf("p2地址=%p\n", p2);
    printf("p2[0]=%d,地址=%p, %p\n", *p2[0], &p2[0], p2[0]);
    printf("p2[1]=%d,地址=%p, %p\n", *p2[1], &p2[1], p2[1]);
    printf("p2[2]=%d,地址=%p, %p\n", *p2[2], &p2[2], p2[2]);

}

void TArrayNegativeIndex(){
    // 数组下标是负数
    int a[] = {1,2,3,4,5};
    printf("a地址=%p,a[0]地址=%p,a[0]=%d\n", a, &a[0], a[0]);
    printf("a地址=%p,a[1]地址=%p,a[0]=%d\n", a, &a[1], a[1]);
    printf("a地址=%p,a[2]地址=%p,a[0]=%d\n", a, &a[2], a[2]);
    printf("a地址=%p,a[3]地址=%p,a[0]=%d\n", a, &a[3], a[3]);
    printf("a地址=%p,a[4]地址=%p,a[0]=%d\n", a, &a[4], a[4]);

    int *p = &a[4];
    printf("p地址=%p,p=%d\n", p, *p);
    // p[-1]指向前一个元素，不建议这样书写，因为a[-1]的地址是不确定的
    printf("p[-1]地址=%p,p=%d\n", &p[-1], p[-1]);
    printf("p[-2]地址=%p,p=%d\n", &p[-2], p[-2]);
}

void TAssert(){
    // https://www.cnblogs.com/lvchaoshun/p/7816288.html
    // assert的作用是先计算表达式 expression ，如果其值为假（即为0），那么它先向stderr打印一条出错信息，然后通过调用 abort 来终止程序运行。
    typedef char *sds;
    assert( 1 + 2 < 3);
    printf("执行成功\n");
}