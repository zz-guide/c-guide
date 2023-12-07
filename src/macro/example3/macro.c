//
// Created by xulei on 2021/11/28.
//

#include <stdio.h>
#include "macro.h"

/**
 * 1.__BEGIN_DECLS 和__END_DECLS
 *  我们编写代码，经常需要c和c++混合使用，为了使 C 代码和 C++ 代码保持互相兼容的过程调用接口，
 *  需要在 C++ 代码里加上 extern “C” 作为符号声明的一部分，为了简化，从而定义了上面的两个宏方面我们使用。
 *
 *
 *  sys/cdefs.h
    #if defined(__cplusplus)
        #define __BEGIN_DECLS   extern "C" {
        #define __END_DECLS     }
    #else
        #define __BEGIN_DECLS
        #define __END_DECLS

 */

void TSpecialMacro() {
    // 一些特殊的宏
}