/*************************************************************************
	> File Name: 120.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon 14 Sep 2020 04:13:43 PM CST
 ************************************************************************/

#include <stdio.h>

int month[13] = {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

int check(int y, int m, int d) {
    if ((y % 4 == 0 && y % 100) || y % 400 == 0)
        month[2]++;
    if (d <= month[m] && d > 0) return 1;
    else return 0;
}

int main() {
    int y, m, d;
    scanf("%d%d%d", &y, &m, &d);
    if (check(y, m, d)) printf("YES\n");
    else printf("NO\n");
    return 0;
}
