//
// Created by xulei on 2022/2/9.
//

#include <stdio.h>
#include <stdlib.h>
#include "struct1.h"
#include <stdbool.h>

struct Student {
    int age;
    char *name;
};

struct Teacher {
    int age;
    char name[0];    // 柔性数组，0或者不写，本质上不算struct的属性，必须声明为结构体的最后一个属性，还得至少包含一个其他的成员
};

struct Classes {
    int age;
    char *name;
};

void TStruct1() {
    // 测试基本用法，初始化，指针，赋值，读取等
    struct Student stu1;
    stu1.age = 21;
    stu1.name = "许磊";
    // 1.结构体变量可以使用.的方式访问结构体的属性
    printf("stu1 age=%d,name=%s,字节数=%lu \n", stu1.age, stu1.name, sizeof stu1);
    // 2.结构体指针可以使用->访问属性
    struct Student *stu2;
    stu2 = &stu1;
    stu2->age = 21;
    stu2->name = "李四";
    printf("stu2->age=%d,name=%s,地址=%p,自身地址=%p \n", stu2->age, stu2->name, stu2, &stu2);
    printf("stu1->age=%d,name=%s,自身地址=%p\n", stu1.age, stu1.name, &stu1);
}

void TStruct2(){
    // 测试 结构体占用的字节数问题，柔性数组问题
    // 柔性数组作用：1.方便管理内存缓冲区 2.减少内存碎片化
    struct Teacher tea1;
    struct Classes cla1;
    // 只声明，不赋值，默认都是对应类型的零值
    // 通过测试sizeof,发现柔性数组不占用空间
    printf("tea1 age=%d,name=%s,字节数=%lu \n", tea1.age, tea1.name, sizeof tea1);
    printf("cla1 age=%d,name=%s,字节数=%lu \n", cla1.age, cla1.name, sizeof cla1);
    // 不占用空间
    int len = 10;
    struct Teacher *p=(struct Teacher*)malloc(sizeof(struct Teacher) + sizeof(int)*len);
    p->age= 123;
    printf("p分配内存 字节数=%lu\n",sizeof(struct Teacher));

    // 单独使用数组时必须指定长度，可以是0
    char arr[0];
}

void TStruct3(){
    // 结构体之间无法比较
    struct Student s1 = {1};
    struct Student s2 = {1};
    printf("s1 == s2 %d\n", &s1 == &s2);

    // stdbool.h， bool不属于基本类型，false 是0，true是1
    bool bl = false;
    bool al = true;
    printf("bl=%d\n", bl);
    printf("al=%d\n", al);
}