//
// Created by xulei on 2019-02-08.
//

#include <stdio.h>
#include "getchar.h"

/**
 * 支持所有平台
 * 最容易理解的字符输入函数是 getchar()，它就是scanf("%c", c)的替代品，除了更加简洁，没有其它优势了；或者说，getchar() 就是 scanf() 的一个简化版本。
 */
void testgetchar() {
    char c;
    c = (char) getchar();
    printf("输入的字符是: %c\n", c);
}

/**
 * warning: this program uses gets(), which is unsafe.gets函数因为没有设置缓存多大，所以使用不安全还会篡改其他变量的值，可以使用fgets替代
 * gets() 是有缓冲区的，每次按下回车键，就代表当前输入结束了，gets() 开始从缓冲区中读取内容，这一点和 scanf() 是一样的。gets() 和 scanf() 的主要区别是：
scanf() 读取字符串时以空格为分隔，遇到空格就认为当前字符串结束了，所以无法读取含有空格的字符串。
gets() 认为空格也是字符串的一部分，只有遇到回车键时才认为字符串输入结束，所以，不管输入了多少个空格，只要不按下回车键，对 gets() 来说就是一个完整的字符串。

也就是说，gets() 能读取含有空格的字符串，而 scanf() 不能。
 */
void testgets() {
    char author[30], lang[30], url[30];
    gets(author);
    printf("author: %s\n", author);
    gets(lang);
    printf("lang: %s\n", lang);
    gets(url);
    printf("url: %s\n", url);
}



/**
 *
 * 只支持windows
 *
 * getche() 就比较有意思了，它没有缓冲区，输入一个字符后会立即读取，不用等待用户按下回车键，这是它和 scanf()、getchar() 的最大区别。
 *
 *
 * getch() 也没有缓冲区，输入一个字符后会立即读取，不用按下回车键，这一点和 getche() 相同。getch() 的特别之处是它没有回显，看不到输入的字符。所谓回显，就是在控制台上显示出用户输入的字符；没有回显，就不会显示用户输入的字符，就好像根本没有输入一样。

    回显在大部分情况下是有必要的，它能够与用户及时交互，让用户清楚地看到自己输入的内容。但在某些特殊情况下，我们却不希望有回显，例如输入密码，有回显是非常危险的，容易被偷窥。
 *
 *
 * */