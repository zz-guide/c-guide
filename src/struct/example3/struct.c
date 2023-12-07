//
// Created by xulei on 2022/2/9.
//

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

/**
 * https://www.jianshu.com/p/90a6eef329ec
 * pragma pack 指令
 */

#pragma pack(push, 1)
struct mysds1 {
    char c;
    int i;
};
#pragma pack(pop)

struct mysds2 {
    char c;
    int i;
};

void TStruct7() {
    printf("mysds1 sizeof=%lu\n", sizeof(struct mysds1));
    printf("mysds2 sizeof=%lu\n", sizeof(struct mysds2));
}