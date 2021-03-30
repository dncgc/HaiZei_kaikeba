/*************************************************************************
	> File Name: 9.27_binary_search.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: 2020年09月27日 星期日 20时03分21秒
 ************************************************************************/

#include <stdio.h>
#include <math.h>

double func(double x) {
    return x * x;
}
//int (*arr)(int)
double binary_search(double (*arr)(double),double x) {
    double head = 0, tail = x / 2.0, mid = 0;
    #define ESPL 1e-6
    while (fabs(arr(mid) - x) > ESPL) {
        mid = (head + tail) / 2;
        if (arr(mid) < x) head = mid + 1;
        else tail = mid - 1;
    }
    #undef ESPL
    return mid;//此处返回零会有歧义
}

int main() {
    double n;
    while (~scanf("%lf", &n)) {
        double x = binary_search(func, n);
        printf("%g * %g = %g\n", x, x, n);
    }
    return 0;
}
