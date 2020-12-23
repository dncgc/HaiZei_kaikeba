/*************************************************************************
	> File Name: 118.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon 14 Sep 2020 03:12:18 PM CST
 ************************************************************************/
// 字符串最后有个'\0',定义数组时记得+1
#include <stdio.h>

char zodiac[12][8] = {
    "rat", "ox", "tiger", "rabbit", "dragon", "snake", "horse", "sheep", "monkey",
    "rooster", "dog", "pig"
};

int main() {
    int year;
    scanf("%d", &year);
    year -= 1900;
    year = (year >= 0 ? year % 12 : year % 12 + 12);
    printf("%s\n", zodiac[year]);
    return 0;
}
