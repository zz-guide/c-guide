#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main()
{
    char* str = "ab";
    printf("str: %s, length: %d, 地址:%p\n", str, strlen(str), &str);

    // 直接修改指针指向的内容
    str = "cd";
    printf("str: %s, length: %d, 地址:%p\n", str, strlen(str), &str);

    char str1[] = "ef";
    // strcpy(str, str1); // 经过测试发现无法将字符串赋值给一个已存在的char*

    char* str2 = (char*)malloc(sizeof(char)*3);
    if (str2 != NULL) {
        strcpy(str2,str1);
        printf("str2: %s, length: %d, 地址:%p\n", str2, strlen(str2), &str2);
    }
    
    return 0;
}