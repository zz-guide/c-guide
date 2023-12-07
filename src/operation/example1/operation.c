//
// Created by xulei on 2018/6/18.
//

#include <printf.h>
#include "operation.h"


void TOperation()
{
    //下边的程序在不同的编译器运算结果是不同的，比如VC编译器和gcc编译器就是不同的
    //解决办法：尽量避免自增和自减运算与其他运算符混合使用，应该单独计算
//    int a = 0;
//    int r = 0;
//
//    r = (++a)+(++a)+(++a);
//
//    printf("结果1:%d\n", a);
//    printf("结果2:%d\n", r);
//
//    r = (a++)+(a++)+(a++);
//
//    printf("结果3:%d\n", a);
//    printf("结果4:%d\n", r);
}

void TOperation1(){
    // a++与++a的区别
    // ++ 在前面叫做前自增（例如 ++a）。前自增先进行自增运算，再进行其他操作。
    // ++ 在后面叫做后自增（例如 a++）。后自增先进行其他操作，再进行自增运算。
    // -- 一样
    // 建议单独进行运算，不同编译器可能出来的结果不同；
    int a = 2;
    printf("a = %d\n", a);
    a++;
    printf("a = %d\n", a);
    ++a;
    printf("a = %d\n", a);
    int c = ++a;
    printf("c = %d\n", c);
    int d = a++;
    printf("d = %d\n", d);
}

void TSwitch(){
    int a = 1;
    // 匹配成功默认执行本case以及之后的case，所以需要加break；
    // default 不是必须的。当没有 default 时，如果所有 case 都匹配失败，那么就什么都不执行。
    switch(a){
        case 1: printf("Monday\n"); break;
        case 2: printf("Tuesday\n"); break;
        case 3: printf("Wednesday\n"); break;
        case 4: printf("Thursday\n"); break;
        case 5: printf("Friday\n"); break;
        case 6: printf("Saturday\n"); break;
        case 7: printf("Sunday\n"); break;
        default:printf("error\n"); break;
    }
}