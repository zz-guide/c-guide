//
// Created by xulei on 2019-02-07.
//

#include <printf.h>
#include <mhash.h>
#include "distribution.h"

void F1() {
//    char name[5] = "hell\0";//这种方式需要多分配一个空字符，并且需要显示执行\0
//    char name1[] = "许磊";//这种方式不需要指定大小，也不需要主动写\0
//    printf("我的名字：%s\n", name);
//    printf("我的名字1：%s\n", name1);

    //1.malloc分配内存的练习,在堆区分配一块指定大小的内存空间，用来存放数据。这块内存空间在函数执行完成后不会被初始化，它们的值是未知的。
//    char name[100];
//    strcpy(name, "你好，世界");

    /* 动态分配内存 */
    //char *description = (char *) malloc(200 * sizeof(char));
//    char *description = (char *) calloc(200, sizeof(char));
//    if (description == NULL) {
//        fprintf(stderr, "Error - unable to allocate required memory\n");
//    } else {
//        strcpy(description, "我擦");
//    }
//
//    printf("Name = %s\n", name);
//    printf("Description: %s\n", description);
//
//    free(description);
//    free(NULL);//释放NULL不会报错

    //2.试验！取反与 == NULL必须大写,NULL必须大写
//    int *a = NULL;
//    int b = 0;
//    char c = '\0';//只声明不初始化指向的是一个垃圾值
//    bool d = false;
//    char e[] = {};
//    printf("结果a：%d\n", !a);
//    printf("结果b：%d\n", !b);
//    printf("结果c：%d\n", !c);
//    printf("结果d：%d\n", !d);
//    printf("结果e：%d\n", !e);//空数组不能用！判空
//    printf("结果e：%d\n", (sizeof(e) / sizeof(int)));//空数组需要使用长度判空

    //3.void *calloc(int num, int size);
    //在内存中动态地分配 num 个长度为 size 的连续空间，并将每一个字节都初始化为 0。所以它的结果是分配了 num*size 个字节长度的内存空间，并且每个字节的值都是0。


    //4.relloc，C 库函数 void *realloc(void *ptr, size_t size) 尝试重新调整之前调用 malloc 或 calloc 所分配的 ptr 所指向的内存块的大小。
//    int input,n;
//    int count = 0;
//    int* numbers = NULL;
//    int* more_numbers = NULL;
//
//    do {
//        printf ("Enter an integer value (0 to end): ");
//        scanf ("%d", &input);
//        count++;
//
//        more_numbers = (int*) realloc (numbers, 1 * sizeof(int));
//
//        if (more_numbers!=NULL) {
//            numbers=more_numbers;
//            numbers[count-1]=input;
//        }
//        else {
//            free (numbers);
//            puts ("Error (re)allocating memory");
//            exit (1);
//        }
//    } while (input!=0);
//
//    printf ("Numbers entered: ");
//    for (n=0;n<count;n++) printf ("%d ",numbers[n]);
//    free (numbers);


    //5.alloc,相对与 malloc、calloc 与 realloc 函数，函数 alloca 是从栈中分配内存空间，内存分配大小为 size。如果内存分配成功，则返回首地址；如果内存分配失败，则返回 NULL。也正因为函数 alloca 是从栈中分配内存空间，因此它会自动释放内存空间，而无需手动释放。
    //6.aligned_alloc,该函数属于 C 标准提供的新函数，用于边界对齐的动态内存分配。该函数按照参数 alignment 规定的对齐方式为对象进行动态存储分配 size 个 size_t 类型的存储单元。如果内存分配成功，则返回首地址；否则内存分配失败，则返回 NULL。
    //相对于 malloc 函数，aligned_alloc 函数保证了返回的地址是能对齐的，同时也要求 size 参数是 alignment 参数的整数倍。从表面上看，函数 calloc 相对 malloc 更接近 aligned_alloc，但 calloc 函数比 aligned_alloc 函数多了一个动作，那就是会将内存内容初始化为 0。



    //7.memset,将s所指向的某一块内存中的每个字节的内容全部设置为ch指定的ASCII值， 块的大小由第三个参数指定，这个函数通常为新申请的内存做初始化工作， 其返回值为指向S的指针。(常用于数组清零)
    int i;  //循环变量
    char str[10];
    char *p = str;
    memset(str, 1, sizeof(str));  //只能写sizeof(str), 不能写sizeof(p)
    for (i=0; i<10; ++i)
    {
        printf("%ul\x20", str[i]);
    }
    printf("\n");

    //8.使用sizeof验证数据类型在内存中占用的空间大小
//    char
//    int
//    short
//    long
//    unsigned int
//    float
//    double
//    long double
//    printf("在64位机器中：\n");
//    printf("        char类型占%d个字节\n",sizeof(char));
//    printf("       short类型占%d个字节\n",sizeof(short));
//    printf("         int类型占%d个字节\n",sizeof(int));
//    printf("        long类型占%d个字节\n",sizeof(long));
//    printf("unsigned int类型占%d个字节\n",sizeof(unsigned int));
//    printf("       float类型占%d个字节\n",sizeof(float));
//    printf("      double类型占%d个字节\n",sizeof(double));
//    printf(" long double类型占%d个字节\n",sizeof(long double));
//    printf("-------------------指针占4个字节---------------------\n");
//    char *p0;
//    short *p1;
//    int *p2;
//    long *p3;
//    unsigned int *p4;
//    float *p5;
//    double *p6;
//    long double *p7;
//    printf("        char类型指针占%d个字节\n",sizeof(p0));
//    printf("       short类型指针占%d个字节\n",sizeof(p1));
//    printf("         int类型指针占%d个字节\n",sizeof(p2));
//    printf("        long类型指针占%d个字节\n",sizeof(p3));
//    printf("unsigned int类型指针占%d个字节\n",sizeof(p4));
//    printf("       float类型指针占%d个字节\n",sizeof(p5));
//    printf("      double类型指针占%d个字节\n",sizeof(p6));
//    printf(" long double类型指针占%d个字节\n",sizeof(p7));

    //定义字符串的几种方式
    //字符串和字符数组的区别：最后一位是否是空字符
//    char names1[] = {'j', 'a', 'c', 'k', '\0'};
//    char names2[50] = "jack";
//    char names3[] = "jackff";
//    char * names4 = "jacksss";

//    printf("数组所占空间大小：%d\n", sizeof(names1));
//    printf("数组所占空间大小：%d\n", sizeof(names2));
//    printf("数组所占空间大小：%d\n", sizeof(names3));
}