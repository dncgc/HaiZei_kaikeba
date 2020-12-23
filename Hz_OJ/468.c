/*************************************************************************
	> File Name: 468.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed Oct  7 08:47:43 2020
 ************************************************************************/

#include <stdio.h>

int gcd(int m, int n) {
    if (!m) return n;
    return gcd(n % m, m);
}

int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    printf("%d\n", gcd(m, n));
    return 0;
}
