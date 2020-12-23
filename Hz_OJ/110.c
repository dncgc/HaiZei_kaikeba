/*************************************************************************
	> File Name: 110.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon 14 Sep 2020 11:11:05 AM CST
 ************************************************************************/

#include <stdio.h>

double fee(double X) {
    double f;
    if (X <= 15) f = 6 * X;
    else f = 6 * 15.0 + (X - 15) * 9;
    return f;
}

int main() {
    double X;
    scanf("%lf", &X);
    printf("%.2lf\n", fee(X));
    return 0;
}
