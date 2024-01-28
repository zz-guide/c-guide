#include <stdio.h>
#include <string.h>

int main()
{
    // 不定长初始化
    printf("=========================\n");
    char str1[] = {"abc"};
    printf("str1: %s, length: %d, sizeof: %d, 地址: %p\n", str1, strlen(str1), sizeof(str1), str1);
    for (int i = 0; i < strlen(str1) +1 ; i++) {
	    printf("str1[%d]: %c\n", i, str1[i]);
	}

    char str2[] = {'a','b','c','\0'};
    printf("=========================\n");
    printf("str2: %s, length: %d, sizeof: %d, 地址: %p\n", str2, strlen(str2), sizeof(str2), str2);
    for (int i = 0; i < strlen(str2) +1 ; i++) {
	    printf("str2[%d]: %c\n", i, str2[i]);
	}

    printf("=========================\n");
    char str3[] = "abc";
    printf("str3: %s, length: %d, sizeof: %d, 地址: %p\n", str3, strlen(str3), sizeof(str3), str3);
    for (int i = 0; i < strlen(str3) +1 ; i++) {
	    printf("str3[%d]: %c\n", i, str3[i]);
	}

    // 定长初始化
    printf("=========================\n");
    char str4[4] = "abc";
    printf("str4: %s, length: %d, sizeof: %d, 地址: %p\n", str4, strlen(str4), sizeof(str4), str4);
    for (int i = 0; i < strlen(str4) +1 ; i++) {
	    printf("str4[%d]: %c\n", i, str4[i]);
	}

    printf("=========================\n");
    char str5[4] = {'a','b','c','\0'};
    printf("str5: %s, length: %d, sizeof: %d, 地址: %p\n", str5, strlen(str5), sizeof(str5), str5);
    for (int i = 0; i < strlen(str5) +1 ; i++) {
	    printf("str5[%d]: %c\n", i, str5[i]);
	}

    printf("=========================\n");
    char str6[4] = {"abc"};
    printf("str6: %s, length: %d, sizeof: %d, 地址: %p\n", str6, strlen(str6), sizeof(str6), str6);
    for (int i = 0; i < strlen(str6) +1 ; i++) {
	    printf("str6[%d]: %c\n", i, str6[i]);
	}
    
    return 0;
}