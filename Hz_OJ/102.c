/*************************************************************************
	> File Name: 102.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sun Sep 13 23:28:32 2020
 ************************************************************************/

#include <stdio.h>

double time(double a, double b, double c, double t) {
    double tt;
    tt = (1 - (1 / a + 1 / b) * t) / (1 / a + 1 / b - 1 / c);
    return tt + t;
}

int main() {
    double a, b, c, t;
    scanf("%lf%lf%lf%lf", &a, &b, &c, &t);
    printf("%.2lf\n", time(a, b, c, t));
    return 0;
}
