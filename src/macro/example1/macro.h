//
// Created by xulei on 2021/11/28.
//

#ifndef MYC_MACRO_H
#define MYC_MACRO_H

// 不带参数宏
#define NAME "许磊" // 字符串值必须用双引号括起来
#define NAME1 xx
#define AGE 21

// 带参数宏
#define SQUARE(x) ((x)*(x))

// # ，像这种语句类的就不能再加括号了，字符串化运算符#参数会处理成"实参"
#define printFloat(exp) printf(#exp" = %f \n", exp)

// ## 记号粘贴运算符
#define TEXT_A "Hello, world!"
#define msg(x) puts( TEXT_ ## x )

#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) > (b) ? (b) : (a))

// 宏内使用宏，先处理#和##,然后检查宏里宏
#define STR(s) #s
#define XSTR(s) STR(s)                   // 将宏s展开，然后字符串化

// #运算符如何修改宏实参中空白符、双引号，以及反斜线
// __VA_ARGS__ 是一个可变参数的宏,实现思想就是宏定义中参数列表的最后一个参数为省略号（也就是三个点）
// __VA_ARGS__ 等价于...
#define my_printf2(...) printf(__VA_ARGS__)
#define my_printf3(fmt, ...) printf(fmt, __VA_ARGS__)
// ##__VA_ARGS__ 宏前面加上##的作用在于，当可变参数的个数为0时，这里的##起到把前面多余的","去掉的作用,否则会编译出错。
#define my_printf4(fmt, ...) printf(fmt, ##__VA_ARGS__)

void TMacro();

#endif //MYC_MACRO_H
