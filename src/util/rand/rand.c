//
// Created by xulei on 2022/2/10.
//

#include "rand.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void TRand(){
    // rand() 会随机生成一个位于 0 ~ RAND_MAX 之间的整数。
    // C语言标准并没有规定 RAND_MAX 的具体数值，只是规定它的值至少为 32767。在实际编程中，我们也不需要知道 RAND_MAX 的具体值，把它当做一个很大的数来对待即可。
    // 不随机播种的话，每次生成的数都一样，伪随机数
    srand((unsigned)time(NULL));
    int randNum= rand() % 51 + 13;
    printf("随机数=%d\n",randNum);
}