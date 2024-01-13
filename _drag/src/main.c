//
// Created by xulei on 2022/2/13.
//
#include <stdio.h>

int main(int argc, char *argv[], char *envp[]) {
    // int argc，存放了命令行参数的个数。

    // 显示参数的个数, ./main 也算一个参数，程序名称也算一个参数
    // argc[0]=程序名
    printf("argc is %d\n", argc);

    // 列出全部的参数
    for (int i = 0; i < argc; i++) {
        printf("argv[%d] is %s\n", i, argv[i]);
    }

    // 不建议使用：envp存放了当前程序运行环境的参数
    int j = 0;

    while (envp[j] != 0)  // 数组最后一个元素是0
    {
        printf("%s\n", envp[j]);
        j++;
    }

    return 0;
}