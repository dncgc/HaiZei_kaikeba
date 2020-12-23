/*************************************************************************
	> File Name: 183.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 22 Sep 2020 10:04:23 AM CST
 ************************************************************************/

#include <stdio.h>

int f(int x) {
    if (x <= 0) return 0;
    if (x == 1) return 1;
    else if (x & 1) return 3 * f((x + 1) / 2) - 1;
    else return 3 * f(x / 2) - 1;
}

int main() {
    int x;
    scanf("%d", &x);
    printf("%d\n", f(x));
    return 0;
}
