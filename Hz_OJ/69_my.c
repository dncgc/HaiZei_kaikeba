/*************************************************************************
	> File Name: 69_my.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat Sep 12 21:07:46 2020
 ************************************************************************/

#include <stdio.h>

int month[13] = {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

int check(int y, int m, int d) {
    if ((y % 4 == 0 && y % 100) || y % 400 == 0)
        month[2]++;
    if (d <= month[m] && d > 0) printf("Yes\n");
    else printf("No\n");
}

int main() {
    int year, month, day;
    scanf("%d%d%d", &year, &month, &day);
    check(year, month, day);
    return 0;
}
