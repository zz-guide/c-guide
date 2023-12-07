//
// Created by xulei on 2018/6/19.
//

#ifndef MYC_TESTLINK_H
#define MYC_TESTLINK_H

#include <stdio.h>
#include <stdlib.h>

#define Size 4

//基本的顺序表结构体
typedef struct {
    int * head;//存放元素
    int length;//长度
    int size;//容量
} table;


table newTable();//初始化顺序表
table add(table t, int index, int elem);//添加元素
table delete(table t, int index);//删除元素
int search(table t, int elem);//查找元素
table update(table t,int elem,int newElem);//修改元素
void var_dump(table t);//打印元素
void handle();//测试方法


#endif //MYC_TESTLINK_H