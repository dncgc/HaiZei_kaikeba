/*************************************************************************
	> File Name: 163.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 19 Sep 2020 11:57:52 AM CST
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#define PI acos(-1)

int main() {
    double a, b, theta;
    scanf("%lf%lf%lf", &a, &b, &theta);
    theta = theta * PI / 180;
    printf("%.6lf\n", sqrt(a * a + b * b - 2 * a * b * cos(theta)));
    return 0;
}
