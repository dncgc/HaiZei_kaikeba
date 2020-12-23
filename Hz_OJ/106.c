/*************************************************************************
	> File Name: 106.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon 14 Sep 2020 10:55:12 AM CST
 ************************************************************************/
//%g 代表实数 不会输出浮点数末尾无意义的0
#include <stdio.h>

int main() {
    double a;
    scanf("%lf", &a);
    if (a < 0) printf("%g\n", -a);
    else printf("%g\n", a);
    return 0;
}
