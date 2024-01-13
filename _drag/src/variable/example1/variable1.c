//
// Created by xulei on 2022/2/10.
//

#include "variable1.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void Tint() {
    // int占4个字节，取值范围 -2147483648 到 2147483647。
    // 1.int变量未初始值是0
    int a;
    printf("a = %d, 地址=%p\n", a, &a);
    // 2.赋值
    a = 5;
    // 3.赋值一个其他类型的值
    // int类型变量是可以赋值一个char类型的，但是汉字不行，character too large for enclosing character literal type
    a =  2147483646; // a = '0'， 48
    // 可以赋值其他类型，但是值没有意义
    a = "s";
    // %d打印的是ascii码
    printf("a = %d, 地址=%p\n", a, &a);
}

void Tchar() {
    // 1.char变量未初始化时，是垃圾值
    char a;
    printf("a = %c, 地址=%p\n", a, &a);
    // 2.赋值,char类型的变量也可以赋值int类型的值
    a = 40;
    a = "ss";   // 垃圾值，乱码
    a = 'abccn'; // 字符中多字符的话，取最后一个字符的值
//    a = '我'; // 汉字字符不兼容，直接报错
    printf("a = %c, 地址=%p\n", a, &a);
}

void Tfloat() {
    // 1.int变量未初始值是0
    float a;
    printf("a = %d, 地址=%p\n", a, &a);
    // 2.赋值
    a = 1;
    printf("a = %d, 地址=%p\n", a, &a);
}

void TDouble() {
    // 1.double变量未初始值是
    double a = 2.3;
    printf("a = %lf, 地址=%p\n", a, &a);
    // 2.赋值
    a = 1;
    printf("a = %lf, 地址=%p\n", a, &a);
}

void TVoid(){
    // 1.void不能修饰变量，编译报错
//    void a;
    //2.void可以修饰函数和指针变量，这个指针变量可以接受任何指针类型的地址，并且也可以转换为任何类型的指针
    void free(void *ptr);
}

void T1(){
    // external和static区别
}


void TTT(){
    const int aa = 2;
    printf("aa =%d\n", aa);
}

void TNumber(){
    unsigned short a = 35527;    // 0~35527
    unsigned short a1 = -1;

    short b = 25615;
    short b1 = -30010;             // 35527 to -30009

    int c = 127;
    unsigned int c1 = 127;

    long d = 1;
    unsigned long d1 = 1;

    long long e = 1;
    unsigned long long e1 = 1;

    long int f = 2;
    unsigned long int f1 = 2;

    char g = 1;
    unsigned char g1 = 1;
    signed g2 = 2;

    // signed和unsigned区别

    printf("char的最小值 CHAR_MIN = %d,字节数=%lu\n", CHAR_MIN, sizeof(char));
    printf("signed char的最大值 SCHAR_MAX = %d,字节数=%lu\n", SCHAR_MAX, sizeof(signed char));
    printf("signed char的最小值 SCHAR_MIN = %d,字节数=%lu\n", SCHAR_MIN, sizeof(signed char));
    printf("unsigned char的最大值 UCHAR_MAX = %d,字节数=%lu\n", UCHAR_MAX, sizeof(unsigned char));
    printf("short的最大值 SHRT_MAX = %d,字节数=%lu\n", SHRT_MAX, sizeof(short));
    printf("short的最小值 SHRT_MIN = %d,字节数=%lu\n", SHRT_MIN, sizeof(short));
    printf("unsigned short的最小值 USHRT_MAX = %d,字节数=%lu\n", USHRT_MAX, sizeof(unsigned short));
    printf("int 的最小值 INT_MAX = %d,字节数=%lu\n", INT_MAX, sizeof(int));
    printf("int 的最小值 INT_MIN = %d,字节数=%lu\n", INT_MIN, sizeof(int));
    printf("unsigned int 的最大值 UINT_MAX = %d,字节数=%lu\n", UINT_MAX, sizeof(unsigned int));
//    printf("int 的最小值 UINT_MIN = %d,字节数=%lu\n", UINT_MIN, sizeof(int));
    printf("long 的最大值 LONG_MAX = %ld,字节数=%lu\n", LONG_MAX, sizeof(long));
    printf("long 的最小值 LONG_MIN = %ld,字节数=%lu\n", LONG_MIN, sizeof(long));
    printf("unsigned long 的最小值 ULONG_MAX = %ld,字节数=%lu\n", ULONG_MAX, sizeof(unsigned long));
//    printf("int 的最小值 FLT_MANT_DIG = %d,字节数=%lu\n", FLT_MANT_DIG, sizeof(int));
//    printf("int 的最小值 FLT_DIG = %d,字节数=%lu\n", FLT_DIG, sizeof(int));
//    printf("int 的最小值 FLT_MIN_10_EXP = %d,字节数=%lu\n", FLT_MIN_10_EXP, sizeof(int));
//    printf("int 的最小值 FLT_MAX_10_EXP = %d,字节数=%lu\n", FLT_MAX_10_EXP, sizeof(int));
//    printf("float类型正数 的最小值 FLT_MIN = %d,字节数=%lu\n", FLT_MIN, sizeof(int));
//    printf("float类型正数 的最大值 FLT_MAX = %d,字节数=%lu\n", FLT_MAX, sizeof(int));

    // size_t
    printf("size_t 字节数sizeof=%lu\n", sizeof(size_t));
    printf("uint64_t 字节数sizeof=%lu\n", sizeof(uint64_t));
    printf("uint8_t 字节数sizeof=%lu\n", sizeof(uint8_t));

    const int aa = 2;
    printf("aa1 =%d\n", aa);
    TTT();

    // 可以修改指向，但是不能修改指向的内容
    const char *constStr = "hasdas";
//    *constStr = "sss";//Read-only variable is not assignable
    printf("constStr 地址=%p\n", constStr);
    char *constStr1 = "ccc";
    constStr = constStr1;
    printf("constStr 地址=%p\n", constStr);
    printf("constStr1 地址=%p\n", constStr1);
}