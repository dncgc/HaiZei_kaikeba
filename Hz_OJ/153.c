/*************************************************************************
	> File Name: 153.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 18 Sep 2020 04:22:35 PM CST
 ************************************************************************/

#include <stdio.h>

int weekday(int year, int month, int day) {
    int j, k, h;
    if (month == 1 || month == 2) {
        month += 12;
        year--;
    }
    j = year / 100;
    k = year % 100;
    h = (day + 26 * (month + 1) / 10 + k + k / 4 + j / 4 + 5 * j) % 7;
    if (h < 2) h += 6;
    else h = h + 6 - 7;
    return h;
}

int main() {
    int y, m, d;
    scanf("%d%d%d", &y, &m, &d);
    printf("%d\n", weekday(y, m, d));
    return 0;
}
