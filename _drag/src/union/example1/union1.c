//
// Created by xulei on 2019-02-08.
//

#include <printf.h>
#include "union1.h"

/**
 * 1.认识位域
 * struct bs{
    unsigned m;
    unsigned n: 4;
    unsigned char ch: 6;
}

 2.大小端判断
 */
void F1() {
    struct {
        char name[20];
        int num;
        char sex;
        char profession;
        union {
            float score;
            char course[20];
        } sc;
    } bodys[TOTAL];

    int i;
    //输入人员信息
    for (i = 0; i < TOTAL; i++) {
        printf("Input info: ");
        scanf("%s %d %c %c", bodys[i].name, &(bodys[i].num), &(bodys[i].sex), &(bodys[i].profession));
        if (bodys[i].profession == 's') {  //如果是学生
            scanf("%f", &bodys[i].sc.score);
        } else {  //如果是老师
            scanf("%s", bodys[i].sc.course);
        }

        fflush(stdin);
    }
    //输出人员信息
    printf("\nName\t\tNum\tSex\tProfession\tScore / Course\n");
    for (i = 0; i < TOTAL; i++) {
        if (bodys[i].profession == 's') {  //如果是学生
            printf("%s\t%d\t%c\t%c\t\t%f\n", bodys[i].name, bodys[i].num, bodys[i].sex, bodys[i].profession,
                   bodys[i].sc.score);
        } else {  //如果是老师
            printf("%s\t%d\t%c\t%c\t\t%s\n", bodys[i].name, bodys[i].num, bodys[i].sex, bodys[i].profession,
                   bodys[i].sc.course);
        }
    }
}