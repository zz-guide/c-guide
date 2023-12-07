//
// Created by xulei on 2019-02-08.
//

#include <stdio.h>
#include "enum1.h"

void testenum() {
    // 枚举值默认从0开始，也可以自己指定
    // 之后不能定义相同名字的变量
    // 枚举值不能取地址，因为放在代码区
    // 每一个值占用字节为4，相当于int整型
    // 只能赋值，不能修改
    enum week{ Mon = 1, Tues, Wed, Thurs, Fri, Sat, Sun } day;

    scanf("%d", &day);
    switch(day){
        case Mon: puts("Monday"); break;
        case Tues: puts("Tuesday"); break;
        case Wed: puts("Wednesday"); break;
        case Thurs: puts("Thursday"); break;
        case Fri: puts("Friday"); break;
        case Sat: puts("Saturday"); break;
        case Sun: puts("Sunday"); break;
        default: puts("Error!");
    }
}