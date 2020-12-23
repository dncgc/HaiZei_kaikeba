/*************************************************************************
	> File Name: 119.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon 14 Sep 2020 03:53:15 PM CST
 ************************************************************************/

#include <stdio.h>

int month[13] = {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

int main() {
    int y, m, d;
    scanf("%d%d%d", &y, &m, &d);
    if ((y % 4 == 0 && y % 100) || y % 400 == 0)
        month[2]++;
    if (d == 1) {
        if (m == 1) {
            printf("%d %d %d\n", y-1, 12, month[12]);
            printf("%d %d %d\n", y, m, d + 1);
        } else {
            printf("%d %d %d\n", y, m-1, month[m-1]);
            printf("%d %d %d\n", y, m, d + 1);
        }
    } else if (d == month[m]) {
        if (m == 12) {
            printf("%d %d %d\n", y, m, d-1);
            printf("%d %d %d\n", y + 1, 1, 1); 
        } else {
            printf("%d %d %d\n", y, m, d-1);
            printf("%d %d %d\n", y, m+1, 1);
        }
    } else {
        printf("%d %d %d\n", y, m, d-1);
        printf("%d %d %d\n", y, m, d + 1);
    }
    return 0;
}
