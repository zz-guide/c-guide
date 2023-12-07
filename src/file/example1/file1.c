//
// Created by xulei on 2022/2/10.
//

#include "file1.h"
#include<stdio.h>

void CharReadFile() {
    // 按字节读取
    FILE *fp;

    //如果文件不存在，给出提示并退出
    if ((fp = fopen("/Users/xulei/jungle/cworkspace/myc/src/file/example1/temp_c.txt", "rt")) == NULL) {
        puts("Fail to open file!");
        return;
    }

    //每次读取一个字节，直到读取完毕
    int ch;
    // 换行符以及末尾的结束符号也会被读出来
    while ((ch = fgetc(fp)) != EOF) {
        printf("当前ch=%c\n", ch);
    }

    printf("\n");
    if (ferror(fp)) {
        printf("读取出错\n");
    } else {
        printf("读取成功\n");
    }

    fclose(fp);
}

void StrReadFile() {
    // 按字符串读取
    FILE *fp;

    //如果文件不存在，给出提示并退出
    if ((fp = fopen("/Users/xulei/jungle/cworkspace/myc/src/file/example1/temp_s.txt", "rt")) == NULL) {
        puts("Fail to open file!");
        return;
    }

    //每次读取一个字节，直到读取完毕
    const int N = 100;
    char str[N + 1];
    // fgets最多读取N,遇到换行或者末尾自动返回，最多读取一行数据，C没有提供按行读取的函数，只要N设置的够大
    while ((fgets(str, N, fp)) != NULL) {
        printf("str=%s\n", str);
    }

    printf("\n");
    if (ferror(fp)) {
        printf("读取出错\n");
    } else {
        printf("读取成功\n");
    }

    fclose(fp);
}

void BlockReadFile() {
    // 按字节块读取
    FILE *fp;

    //如果文件不存在，给出提示并退出
    if ((fp = fopen("/Users/xulei/jungle/cworkspace/myc/src/file/example1/temp_c.txt", "rb")) == NULL) {
        puts("Fail to open file!");
        return;
    }

    const int N = 100;
    //从文件读取内容并保存到数组b
    int size = sizeof(int);
    int b[N];
    fread(b, size, N, fp);
    //在屏幕上显示数组b的内容
    for (int i = 0; i < N; i++) {
        printf("当前字符: %d=%c\n", i, b[i]);
    }

    printf("\n");
    if (ferror(fp)) {
        printf("读取出错\n");
    } else {
        printf("读取成功\n");
    }

    fclose(fp);
}