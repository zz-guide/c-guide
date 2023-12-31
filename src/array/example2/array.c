//
// Created by xulei on 2022/2/10.
//

#include <stdio.h>
#include "array.h"

//#define MAX 10

/*
 * 结论：
 *
 *
 *
 *
 *
 * */


void TArray11() {
    // 多维数组
    int a[3][5] = {
        {1, 2, 3, 4, 5},   /*  初始化索引号为 0 的行 */
        {2, 2, 3, 4},   /*  初始化索引号为 1 的行 */
        {3, 2, 3, 4}    /*  初始化索引号为 2 的行 */
    };
    int b[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};  // 与上边的初始化等价
    // 通过打印地址发现，多维数组的内存空间是挨着的，其实就是拆分成多个一维数组紧挨
    // 所以才可以一字排开式的初始化

    // 数组名仍然是代表数组的首个元素的地址，a[0][0]
    printf("a地址=%p\n", a);
    printf("\n");
    printf("a[0][0]=%d,地址=%p\n", a[0][0], &a[0][0]);
    printf("a[0][1]=%d,地址=%p\n", a[0][1], &a[0][1]);
    printf("a[0][2]=%d,地址=%p\n", a[0][2], &a[0][2]);
    printf("a[0][3]=%d,地址=%p\n", a[0][3], &a[0][3]);
    printf("a[0][4]=%d,地址=%p\n", a[0][4], &a[0][4]);
    printf("\n");
    printf("a[1][0]=%d,地址=%p\n", a[1][0], &a[1][0]);
    printf("a[1][1]=%d,地址=%p\n", a[1][1], &a[1][1]);
    printf("\n");
    printf("a[2][0]=%d,地址=%p\n", a[2][0], &a[2][0]);
    printf("a[2][1]=%d,地址=%p\n", a[2][1], &a[2][1]);
    printf("\n");
}