//
// Created by xulei on 2022/2/10.
//

#include "const.h"
#include <stdio.h>

void TConst() {
    const int ID = 1;
    const float MONEY = 1.0;
    const double DDD = 1.111;
    const char A = 'a';
    const char *NAME = "许磊";
    char *name = "许磊";
    printf("ID=%d,地址=%p \n", ID, &ID);
    printf("A=%c,地址=%p \n", A, &A);
    printf("MONEY=%f,地址=%p \n", MONEY, &MONEY);
    printf("DDD=%lf,地址=%p \n", DDD, &DDD);
    printf("NAME=%s,地址=%p \n", NAME, NAME);
    printf("name=%s,地址=%p \n", name, name);
}