//
// Created by xulei on 2022/2/17.
//
#include <stdio.h>

int main() {
    for (int i = 0; i < 10; ++i) {
        int a = i;
        printf("a=%d,地址=%p\n", a, &a);
    }

    return 0;
}