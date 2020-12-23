/*************************************************************************
	> File Name: 196.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 24 Sep 2020 10:59:24 AM CST
 ************************************************************************/

#include <stdio.h>

int step(int n) {
    if (n < 2) return 0;
    return (n == 2 || n == 3) ? 1 : step(n - 2) + step(n - 3);
}

int main() {
    int N;
    scanf("%d", &N);
    printf("%d\n", step(N));
    return 0;
}
