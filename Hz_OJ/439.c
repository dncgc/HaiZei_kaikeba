/*************************************************************************
	> File Name: 439.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sun Oct  4 11:31:30 2020
 ************************************************************************/

#include <stdio.h>

int action(double x) {
    double d = 2, distance = 2;
    int act = 1;
    while (distance < x) {
        d *= 0.98;
        distance += d;
        ++act;
    }
    return act;
}

int main() {
    double x;
    scanf("%lf", &x);
    printf("%d\n", action(x));
    return 0;
}
