#include <stdio.h>
#include <string.h>

int main()
{
    char str[3] = "ab";
    printf("str: %s, length: %d, 地址:%p\n", str, strlen(str), &str);

    str[0] = 'c';
    str[1] = 'd';
    printf("str: %s, length: %d, 地址:%p\n", str, strlen(str), &str);

    strcpy(str, "ef");
    printf("str: %s, length: %d, 地址:%p\n", str, strlen(str), &str);
    
    // 或者将一个字符数组赋值给另一个字符数组
    char strCopy[] = {0};
    strcpy(strCopy, str);
    printf("strCopy: %s, length: %d, 地址:%p\n", strCopy, strlen(strCopy), &strCopy);
    return 0;
}