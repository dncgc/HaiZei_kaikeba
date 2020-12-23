/*************************************************************************
	> File Name: third_search.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 26 Nov 2020 02:38:51 PM CST
 ************************************************************************/

#include <stdio.h>

#define ERROR 1e-6
#define swap(a, b) {\
    __typeof(a) _a = a;\
    a = b; b = _a;\
}

double fx(double x) {
    return x * x - 2 * x - 1;
}

double third_search(double (*f)(double), double x1, double x2) {
    if (x1 > x2) swap(x1, x2);
    double mid1, mid2;
    while (x2 - x1 > ERROR) {
        mid1 = x1 + (x2 - x1) / 3;
        mid2 = x2 - (x2 - x1) / 3;
        if (f(mid2) < f(mid1)) x1 = mid1;
        else x2 = mid2;
    }
    return f(x1);
}

int main() {
    int x1, x2;
    scanf("%d%d", &x1, &x2);
    printf("%lf\n", third_search(fx, x1, x2));
    return 0;
}
