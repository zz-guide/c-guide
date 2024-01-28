#include <stdio.h>
#include <string.h>

int main()
{
    // 字符串中间双引号的空白会被去掉
    char* str = "hello world";
    printf("str: %s, length: %d, sizeof: %d, 地址: %p\n", str, strlen(str), sizeof(str), str);

    char* str1 = "hello ""world";
    printf("str1: %s, length: %d, sizeof: %d, 地址: %p\n", str1, strlen(str1), sizeof(str1), str1);

    char* str2 = "hello " "world";
    printf("str2: %s, length: %d, sizeof: %d, 地址: %p\n", str2, strlen(str2), sizeof(str2), str2);

    char* str3 = "hello \"\"world";
    printf("str3: %s, length: %d, sizeof: %d, 地址: %p\n", str3, strlen(str3), sizeof(str3), str3);

    // 单引号不影响
    char* str4 = "hello ''world";
    printf("str4: %s, length: %d, sizeof: %d, 地址: %p\n", str4, strlen(str4), sizeof(str4), str4);

    char* str5 = "hello ' 'world";
    printf("str5: %s, length: %d, sizeof: %d, 地址: %p\n", str5, strlen(str5), sizeof(str5), str5);

    return 0;
}