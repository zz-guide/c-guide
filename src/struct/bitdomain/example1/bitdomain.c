//
// Created by xulei on 2022/2/11.
//

#include "bitdomain.h"


/**
 * 网址：https://blog.csdn.net/weixin_33738982/article/details/88216515
 * 有些信息在存储时，并不需要占用一个完整的字节，而只需占几个或一个二进制位。为了节省存储空间，并使处理简便，C 语言又提供了一种数据结构，称为"位域"或"位段"。
 * 所谓"位域"是把一个字节中的二进位划分为几个不同的区域，并说明每个区域的位数。每个域有一个域名，允许在程序中按域名进行操作。这样就可以把几个不同的对象用一个字节的二进制位域来表示。
* 位域：
    结构体使用位域的主要目的是压缩存储，位域成员不能单独被取sizeof值。C99规定int,unsigned int,bool可以作为位域类型，但编译器几乎都对此做了扩展，允许其它类型存在。结构体中含有位域字段，除了要遵循上面3个准则，还要遵循以下4个规则：
    如果相邻位域字端的类型相同，且位宽之和小于类型的sizeof大小，则后一个字段将紧邻前一个字段存储，直到不能容纳为止。
    如果相邻位域字段的类型相同，但位宽之和大于类型的sizeof大小，则后一个字段将从新的存储单元开始，其偏移量为其类型大小的整数倍。
    如果相邻的位域字段的类型不同，则各编译器的具体实现有差异，VC6采取不压缩方式，Dev-C++采取压缩方式。
    如果位域字段之间穿插着非位域字段，则不进行压缩。
 *
*/

typedef struct A {
    char f1:3;
    char f2:4;
    char f3:5;
    char f4:4;
} a;

typedef struct B {
    char  f1:3;
    short f2:13;
}b;


typedef struct C {
    char f1:3;
    char f2;
    char f3:5;
}c;

typedef struct D {
    char f1:3;
    char :0;
    char :4;
    char f3:5;
}d;


typedef struct E {
    int f1:3;
}e;

void TBitDomain(){
    printf("size of struct A: %lu\n",sizeof(a));
    printf("size of struct B: %lu\n",sizeof(b));
    printf("size of struct C: %lu\n",sizeof(c));
    printf("size of struct D: %lu\n",sizeof(d));
    printf("size of struct E: %lu\n",sizeof(e));
}