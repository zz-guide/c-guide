//
// Created by xulei on 2022/2/10.
//

#include <stdio.h>
#include "array1.h"

//#define MAX 10

/*
 * 结论：
 *  1.sizeof返回值为unsigned long,看系统架构和编译器
 *  2.数组名=首地址=数组第一个元素地址，a=&a=&a[0]
 *  3.数组作为函数参数传递的时候，实际传递的是指向数组a的指针，数组名代表的是数组的地址。要在传递数组前，将该数组的长度算出来，然后一并作为参数传过来。
 *  4.当赋值的元素少于数组总体元素的时候，剩余的元素自动初始化为 0：
    对于short、int、long，就是整数 0；
    对于char，就是字符 '\0'；
    对于float、double，就是小数 0.0。
    5.定义的元素比长度多的话会有警告，不影响运行，这个看各自的编译器实现
 *
 *
 *
 *
 *
 * */

void PrintArray1(int *arr, int size){
    printf("arr字节数=%lu\n", sizeof(arr));
    for (int i = 0; i < size; i++ )
    {
        printf("元素: arr[%d]=%d, 地址=%p \n", i, arr[i], &arr[i]);
    }

    printf("数组arr->首地址=%p, %p, 长度=%d\n", arr, &arr[0], size);
    printf("数组arr[0]=%d\n", *arr);
}

void PrintArray(int arr[], int size){
    // 数组作为函数参数的时候，本质上是一个指针变量，对指针变量使用sizeof 64位就是8
    // 所以以后不能在参数是数组的函数内部使用sizeof对数组求大小，没有意义
    printf("arr字节数=%lu\n", sizeof(arr));
    for (int i = 0; i < size; i++ )
    {
        printf("元素: arr[%d]=%d, 地址=%p \n", i, arr[i], &arr[i]);
    }

    printf("数组arr->首地址=%p, %p, 长度=%d\n", arr, &arr[0], size);
    printf("数组arr[0]=%d\n", *arr);
}

void TArray1(){
    // 1.数组的基本用法,初始化的多余元素不会报错，是一个warning,真实的数组中不会添加进去
    int arr[5] = {1,2,3,4,5};
    PrintArray(arr, sizeof arr/sizeof(int));

    // 2.空数组，空数组的第一个值是随机的，
    int arr1[0];
    PrintArray(arr1, sizeof arr1/sizeof(int));
}

void TArray2(){
    // 1.越界只是warning，不会crash
    // 2.溢出不会造成crash
//    int a[5] = {1,2,3,4,1111111111111111};
//    printf("a[6] = %d\n", a[4]);

    int arr[3] = {2,2,3};
    PrintArray1(arr, 3);
    printf("arr 字节数=%lu\n", sizeof(arr));
    printf("arr 元素个数=%lu个\n", sizeof(arr)/sizeof(arr[0]));
//    int *p = arr;
    // 这四个等价
//    printf("arr 首地址=%p,%p,%p,%p\n", arr, &arr[0], p, &*p);
//    printf("arr[0]=%d\n", *p);
//    printf("arr[0]=%d\n", arr[0]);
//    printf("arr[1]=%d\n", *(p+1));
//    printf("arr[2]=%d\n", *(p+2));
//    printf("arr[3]=%d\n", *(p+3));
    // 数组长度不能使用const变量
    // 使用单个指示符为数组的两段“分配”空间, 如果 MAX 大于 10，数组中间将用 0 值元素进行填充（填充的个数为 MAX-10，并从 a[5] 开始进行 0 值填充）；如果 MAX 小于 10，“[MAX-5]”之前的 5 个元素（1，2，3，4，5）中将有几个被“[MAX-5]”之后的 5 个元素（6，7，8，9，10）所覆盖
//    const int MAX = 8;
//    int a[MAX]={1,2,3,4,5,[MAX-5]=6,7,8,9,10};
//    PrintArray(a, MAX);
}

void TArray3(){
    // 指针数组和数组指针
    // 指针数组：一个指针变量指向了数组，int (*p)[5]
    // 数组指针：数组里的元素是指针, int *p[5]

    // 指针数组的运算，加减
    int arr[3] = {1,2,3};
    int *p = arr;
    printf("arr[0]=%d\n", *p);
    printf("arr[1]=%d\n", *(p+1));
    printf("arr[2]=%d\n", *(p+2));
    printf("arr[3]=%d\n", *(p+3));
    PrintArray(arr, sizeof arr/sizeof(int));
    printf("数组arr[0]=%d,地址=%p\n", *p, p);
    int *p1 = arr+1;
    printf("数组arr[1]=%d,地址=%p\n", *p1, p1);
    int *p2 = arr+2;
    printf("数组arr[2]=%d,地址=%p\n", *p2, p2);
}

void TArray4(){
    // 多维数组
    int j[2][3] = {{1,3,3},{2,2,3}};
    printf("%d\n", j[1][2]);
    //二维数组未赋值的时候，值是随机的
    for(int p = 0;p<3;p++) {
        for(int k = 0;k<4;k++) {
            printf("p=%d,k=%d\n", p, k);

        }
    }
}