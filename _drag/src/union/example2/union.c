//
// Created by xulei on 2018/6/16.
//

#include "union.h"
#include <stdio.h>
#include <stdlib.h>

union myu {
    char u2;
    int u1;
    float u3;
    double u4;
    char n[20];
};

struct {
    int age;
    union {
        int score;
        char course[20];
    } sc;
} Student;

void TUnion() {
    union myu union1;
    union1.u1 = 12;
    union1.u2 = 'h';
    printf("union u1=%d, u2=%c, u3=%f \n",union1.u1, union1.u2, union1.u3);
    // 成员变量内存最大的算,然后对齐字节
    printf("union内存占用 %lu \n", sizeof(union1));
}
