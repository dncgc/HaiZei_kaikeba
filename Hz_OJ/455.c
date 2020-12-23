/*************************************************************************
	> File Name: 455.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon Oct  5 16:22:43 2020
 ************************************************************************/

#include <stdio.h>
#define swap(a, b) {\
    __typeof(a) _a = a;\
    a = b; b = _a;\
}

int gcd(int a, int c) {
    if (a == 0) return c;
    if (a > c) return gcd(c, a);
    return gcd(c - a, a);
}

void simplify_print(int a, int c) {
    printf("%d/%d\n", a / gcd(a, c), c / gcd(a, c));
}

int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);
    simplify_print(a, c);
    return 0;
}
