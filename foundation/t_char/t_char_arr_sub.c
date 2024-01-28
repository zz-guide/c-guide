#include <stdio.h>
#include <string.h>

int main()
{
    // 字符串被截断
    char* str = "hello\0world";
    printf("str: %s, length: %d, sizeof: %d, 地址: %p\n", str, strlen(str), sizeof(str), str);

    char str1[3] = {'a', 'b', 'c'};
    printf("str1: %s, length: %d, sizeof: %d, 地址: %p\n", str1, strlen(str1), sizeof(str1), str1);

    return 0;
}