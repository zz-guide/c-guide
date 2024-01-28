#include <stdio.h>
#include <memory.h>

static int arr_static_global[6]; // 定义全局静态数组
int arr_global[6]; // 定义全局数组

int main()
{
    // 只定义数组，并未初始化;各数组元素的值将是垃圾值。局部变量处于堆栈区，其数值是随机的，即当时内存中的值;
    printf("=========================\n");
    int arr1[6];
    for (int i = 0; i < 6; i++){
		  printf("arr1[%d]=%d\n", i, arr1[i]);
    }

    printf("the arr1[] lement of size is %d\n", sizeof(arr1) / sizeof(arr1[0]));

    // 数组元素全部初始化为0
    printf("=========================\n");
    int arr2[6] = {0};
    for (int i = 0; i < 6; i++){
		  printf("arr2[%d]=%d\n", i, arr2[i]);
    }
    
    printf("the arr2[] lement of size is %d\n", sizeof(arr2) / sizeof(arr2[0]));

	  // 只初始化第一个元素为1，其余为0
	  printf("=========================\n");
    int arr3[6] = {1};
    for (int i = 0; i < 6; i++){
		  printf("arr3[%d]=%d\n", i, arr3[i]);
    }

    printf("the arr3[] lement of size is %d\n", sizeof(arr3) / sizeof(arr3[0]));

	  // 只初始化前边对应未知元素，其余元素值为0
    printf("=========================\n");
    int arr4[6] = {1,2,3};
    for (int i = 0; i < 6; i++){
		  printf("arr4[%d]=%d\n", i, arr4[i]);
    }

    printf("the arr4[] lement of size is %d\n", sizeof(arr4) / sizeof(arr4[0]));

    // 不定长数组初始化,采用给定值进行初始化
    printf("=========================\n");
    int arr5[] = { 1, 2, 3, 4, 5, 6};
    for (int i = 0; i < 6; i++){
		  printf("arr5[%d]=%d\n", i, arr5[i]);
    }

    printf("the arr5[] lement of size is %d\n", sizeof(arr5) / sizeof(arr5[0]));

    // for循环初始化
    printf("=========================\n");
    int arr6[6];
    arr6[0]=1;
    arr6[1]=2;
    arr6[2]=3;
    arr6[3]=4;
    arr6[4]=5;
    arr6[5]=6;
    for (int i = 0; i < 6; i++){
		  printf("arr6[%d]=%d\n", i, arr6[i]);
    }

    printf("the arr6[] lement of size is %d\n", sizeof(arr6) / sizeof(arr6[0]));

    // memset 初始化
    printf("=========================\n");
    int arr7[6] = {0};
    memset(arr7, -1, sizeof(arr7));
    for (int i = 0; i < 6; i++){
		  printf("arr7[%d]=%d\n", i, arr7[i]);
    }

    printf("the arr7[] lement of size is %d\n", sizeof(arr7) / sizeof(arr7[0]));

    // 定义静态局部变量，未初始化，系统会自动初始化为0;
    printf("=========================\n");
    static int arr_local_static[6];
    for (int i = 0; i < 6; i++){
		  printf("arr_local_static[%d]=%d\n", i, arr_local_static[i]);
    }

    printf("the arr_local_static[] lement of size is %d\n", sizeof(arr_local_static) / sizeof(arr_local_static[0]));

    // 全局静态数组，在未初始化时，系统自动初始化为O;
    printf("=========================\n");
    for (int i = 0; i < 6; i++){
		  printf("arr_static_global[%d]=%d\n", i, arr_static_global[i]);
    }

    printf("the arr_static_global[] lement of size is %d\n", sizeof(arr_static_global) / sizeof(arr_static_global[0]));

    // 全局数组，在未初始化时，系统自动初始化为O;
    printf("=========================\n");
    for (int i = 0; i < 6; i++){
		  printf("arr_global[%d]=%d\n", i, arr_global[i]);
    }

    printf("the arr_global[] lement of size is %d\n", sizeof(arr_global) / sizeof(arr_global[0]));

    return 0;
}