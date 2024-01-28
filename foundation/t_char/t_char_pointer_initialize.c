#include <stdio.h>
#include <memory.h>
#include <string.h>
 #include<malloc.h>

int main()
{
    // 指针形式的字符串初始化
    char* str = "abc";
    printf("str: %s, length: %d, sizeof: %d, 地址: %p\n", str, strlen(str), sizeof(str), str);

    // memset初始化
    char* str1 = NULL;
    str1 = (char*)malloc(3*(sizeof(char)));// 分配堆空间 
    memset(str1, 'c', sizeof(char)*3);
    printf("str1: %s, length: %d, sizeof: %d, 地址: %p\n", str1, strlen(str1), sizeof(str1), str1);

    return 0;
}