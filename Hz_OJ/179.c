/*************************************************************************
	> File Name: 179.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon 21 Sep 2020 03:31:15 PM CST
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#define EPSILON 1e-7

double bisection(int p, int q, double (*func)(int, int, double));
double f(int p, int q, double x);
int main() {
        int p;
        int q;
        scanf("%d %d", &p, &q);
        printf("%.4lf\n", bisection(p, q, f));
        return 0;

}

double bisection(int p, int q, double (*func)(int, int, double)) {
    double begin = -20, end = 20, mid = (begin + end) / 2;
    while(fabs(func(p, q, mid)) >= EPSILON) {
        if (func(p, q, mid) * func(p, q, begin) > 0) begin = mid;
        else end = mid;
        mid = (begin + end) / 2;
    }
    return mid;
}

double f(int p, int q, double x) {
        return p * x + q;
}
