//
// Created by xulei on 2018/6/19.
//

#include "testlink.h"

table newTable()
{
    table t;
    t.head=(int*)malloc(Size * sizeof(int));
    if (!t.head) {
        printf("初始化失败");
        exit(-1);
    }

    t.length=0;
    t.size=Size;

    return t;
}

/**
 * 添加元素
 * @param t
 * @param elem
 * @param add
 * @return
 */
table add(table t, int index, int elem)
{
    if (index > t.length + 1 || index < 1) {
        printf("插入位置有问题");
        return t;
    }
    if (t.length >= t.size) {
        //扩容
        t.head=(int *)realloc(t.head, (t.size+1) * sizeof(int));
        if (!t.head) {
            printf("存储分配失败");
        }

        t.size += 1;
    }

    //向后移动其他元素
    for (int i = t.length-1; i >= index-1; i--) {
        t.head[i+1] = t.head[i];
    }

    //赋值
    t.head[index-1] = elem;

    t.length++;

    return t;
}

/**
 * 删除元素
 * @param t
 * @param add
 * @return
 */
table delete(table t, int index)
{
    if (index > t.length || index < 1) {
        printf("被删除元素的位置有误");
        exit(0);
    }

    for (int i = index; i < t.length; i++) {
        t.head[i-1] = t.head[i];
    }

    t.length--;

    return t;
}

/**
 * 查找元素，返回索引位置
 * @param t
 * @param elem
 * @return
 */
int search(table t, int elem){
    for (int i = 0; i < t.length; i++) {
        if (t.head[i] == elem) {
            return i;
        }
    }

    return -1;
}

/**
 * 修改元素的值
 * @param t
 * @param elem
 * @param newElem
 * @return
 */
table update(table t, int elem, int newElem){
    int add = search(t, elem);
    t.head[add-1] = newElem;
    return t;
}

void var_dump(table t){
    for (int i = 0; i < t.length; i++) {
        printf("%d", t.head[i]);
    }

    printf("\n");
}


void handle() {

    table t1 = newTable();

    for (int i = 1; i <= Size; i++) {
        t1.head[i-1] = i;
        t1.length++;
    }

    printf("原顺序表：\n");
    var_dump(t1);

    printf("在第2的位置插入元素5:\n");
    t1 = add(t1, 2, 5);
    var_dump(t1);

    printf("删除元素1:\n");
    t1 = delete(t1, 1);
    var_dump(t1);

    printf("查找元素3的位置:\n");
    int index = search(t1, 3);
    printf("%d\n",index);

    printf("将元素3改为6:\n");
    t1 = update(t1, 3, 6);
    var_dump(t1);
}