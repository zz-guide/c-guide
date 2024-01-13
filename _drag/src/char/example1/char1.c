//
// Created by xulei on 2021/11/28.
//

#include <stdio.h>
#include <string.h>
#include "char1.h"

/**
 * 结论:
 *  1.字符数组的长度包含了'\0',如果不包含的话可能有未知数据。
 *  2.c语言不会对数组进行越界检查,可以编译通过,但会导致数据不正确,使用的时候需要注意。
 */

void TChar1(){
    // 1.固定长度分配，一个位置一个位置赋值，长度设置为真实字符个数+1
//    char arr[2];
//    char arr[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
//    arr[0] = 'h';
//    arr[1] = 'e';
//    arr[2] = 'l';
//    arr[3] = 'l';
//    arr[4] = 'o';
//    arr[5] = '\0';
//    printf("字符数组->arr=%s,长度=%lu,字节数=%lu \n", arr, strlen(arr), sizeof arr);

    // 2.动态字符串赋值方式，sizeof包含了\0的长度
//    char arr1[] = "hello";
//    printf("字符数组->arr1=%s,长度=%lu,字节数=%lu \n", arr1, strlen(arr1), sizeof arr1);

    // 3.如果中间有\0,strlen会直接返回,sizeof不变,会计算全部的长度
//    char arr2[] = "he\0llo";
//    printf("字符数组->arr2=%s,长度=%lu,字节数=%lu \n", arr2, strlen(arr2), sizeof arr2);

    // 3.空字符串,空字符串的字节数是1不是0，因为有\0的存在，但长度是0
//    char arr3[] = "";
//    printf("字符数组->arr3=%s,长度=%lu,字节数=%lu \n", arr3, strlen(arr3), sizeof arr3);

    // 4.字符串指针可以指向数组名
//    char arr4[] = "hello";
//    char *p = arr4; //定义一个指针变量，里面存放字符数组的首地址
//    printf("字符数组->arr4,p =%s,长度=%lu,字节数=%lu \n", p, strlen(p), sizeof p);

    // 5. 可以使用一个char类型的指针直接指向字符串
    // 6.字符串一旦被创建就存在于常量池中,以字符数组形式创建的字符串，实际上是从字符串常量池中复制了一个副本，
    // 所以修改字符数组的内容时，只是修改的自己的副本，并不会影响到常量池中的字符串。而对字符串指针strp操作时会影响到常量池中的字符串
    char *p = "hello";  // 常量池
    char *p1 = "hello"; // 常量池
    char p2[] = "hello"; // 副本
    printf("字符数组->p =%s,长度=%lu,地址=%p,变量地址=%p \n", p, strlen(p), p, &p);
    printf("字符数组->p1 =%s,长度=%lu,地址=%p,变量地址=%p \n", p1, strlen(p1), p1, &p1);
    printf("字符数组->p2 =%s,长度=%lu,地址=%p,变量地址=%p \n", p2, strlen(p2), p2, &p2);
}

void TChar2(){
    // 指针形式的字符串是不能修改的
    char *str = "我xulei";
//    str[0] = 's';
    printf("str=%s,长度=%lu \n", str, strlen(str));
    printf("%c\n", str[0]);
    /*
    在C语言中并没有直接提供字符串的操作，其字符串操作是通过转化为字符串完成的，例如字符数组，字符指针，其本质是对字符的操作。
    作为字符数组，与普通数组相同，区别在于它的每一个元素是一个字符，所以不可以直接用“=”对字符数组赋值（parr[]=”zhifushuzu”，是错误的赋值方式），但是可以对每一个元素进行赋值（charr[12]=’\0’是正确的）。
    字符串一定是以’\0’结尾的；字符数组和字符指针我们当做字符串整体初始化，系统会自动添加’\0’;对于字符数组，如果采用单个字符的方式进行初始化或者赋值一定要考虑结束符’\0’
    strcpy和strcat内部也是对字符的操作，以‘\0’作为字符串结束的标志。
 */
}

void Tchar3(){
    // char和int可以互相转化
    // char 本身只有1个字节，无法保存汉字，只能保存简单字符， 大小为：-128~127
    char c = 127;
}