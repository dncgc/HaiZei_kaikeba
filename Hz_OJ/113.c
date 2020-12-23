/*************************************************************************
	> File Name: 113.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon 14 Sep 2020 11:26:03 AM CST
 ************************************************************************/

#include <stdio.h>

int month[13] = {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

int main() {
    int y, m;
    scanf("%d%d", &y, &m);
    if ((y % 4 == 0 && y % 100) || y % 400 == 0) month[2]++;
    printf("%d\n", month[m]);
    return 0;
}
