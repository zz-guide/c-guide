//
// Created by xulei on 2021/11/28.
//

#include <stdio.h>
#include "macro.h"

/**
    * 结论
    * 1.宏可以定义在函数内
    * 2.宏的后边不能加分号
    * 3.如果是字符串需要用双引号引起来
    * 4.#形参方式称为字符串化运算符，当形参名称出现在替换文本中，并且具有前缀 # 字符时，预处理器会把与该形参对应的实参放到一对双引号中，形成一个字符串字面量。
    * 5.出现在 ## 运算符前后的空白符连同 ## 运算符本身一起被删除。
    * 6.##运算符会把左、右操作数结合在一起，作为一个记号，因此，它常常被称为记号粘贴运算符（token-pasting operator）
    * 7.使用 ## 运算符时，至少有一个操作数是宏的形参。在这种情况下，实参值会先替换形参，然后等记号粘贴完成后，才进行宏展开
    * 8.字符串化运算符和记号粘贴运算符并没有固定的运算次序。如果需要采取特定的运算次序，可以将一个宏分解为多个宏。
    * 9.#undef 宏名称 取消定义一个宏，若不存在则编译器忽略该命令
    * 10.宏不可以递归
    * 11.宏遵循大写规则
    *
    *
*/

void TMacro() {
    // 1. 正常无参宏替换
//    char *name = NAME;
//    int age = AGE;
//    printf("name=%s,地址=%p\n", name, name);
//    printf("age=%d,地址=%p\n", age, &age);

//    报错
//    char *name1 = NAME1;
//    printf("name1=%s,地址=%p\n", name1, name1);

    // 2.带参数的宏替换
//    int square = SQUARE(5);
//    int c = (6);
//    printf("square=%d\n", square);
//    printf("c=%d\n", c);
//    printFloat(12.66);
//    msg(A);
//    int max = MAX(2, 5);
//    int min = MIN(2, 5);
//    printf("max=%d\n", max);
//    printf("min=%d\n", min);

//    char a[] = XSTR("穷叉叉");
//    printf("a=%s\n", a);

//    my_printf2("a is %d\n", 100);
//    my_printf3("aa is %d\n", 50);
//    my_printf4("a is %d\n", 100);
//    my_printf4("I am xulei\n");
//    my_printf3("可变参数个数为0报错\n");
}