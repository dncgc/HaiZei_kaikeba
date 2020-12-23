/*************************************************************************
	> File Name: 135.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 15 Sep 2020 11:42:03 AM CST
 ************************************************************************/

#include <stdio.h>

int month[13] = {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

int main() {
    int x, y, m, d;
    scanf("%d%d%d%d", &x, &y, &m, &d);
    d += x;
    do {
        if ((y % 4 == 0 && y % 100) || y % 400 == 0) 
            month[2] = 29;
        else month[2] = 28;
        if (d > month[m]) {
            d = d - month[m];
            m++;
        }
        if (m > 12) {
            m = m -12;
            y++;
        }
    } while (d > month[m]);
   printf("%d %d %d\n", y, m, d);
    return 0;
}
