//
// Created by xulei on 2022/2/9.
//

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

/**
 * 结构体内存字节对齐
 *
 */

struct mysds1 {
    char c;
    int i;
};

struct mysds2 {
    int i;
    char c;
};

void TStruct8() {
    printf("mysds1 sizeof=%lu\n", sizeof(struct mysds1));
    printf("mysds2 sizeof=%lu\n", sizeof(struct mysds2));
}