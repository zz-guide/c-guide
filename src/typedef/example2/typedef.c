//
// Created by xulei on 2021/11/28.
//

#include "./typedef.h"
#include<stdio.h>

int add(int a, int b) {
    return a + b;
}

int sub(int a, int b) {
    return a - b;
}

// 2种方法等价

// 方法1
typedef int (*calc)(int, int);

calc select1(char op);

// 方法2
int (*select(char))(int, int);

calc select1(char op) {
    switch (op) {
        case '-':
            return sub;
        case '+':
            return add;
        default:
            return NULL;
    }
}

int (*select(char op))(int, int) {
    switch (op) {
        case '-':
            return sub;
        case '+':
            return add;
        default:
            return NULL;
    }
}

void TTypedef1() {
    char op = '+';
    int (*fp)(int, int) = select(op);
    int res = fp(1, 2);
    printf("res=%d\n", res);
}