/*************************************************************************
	> File Name: 442.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sun Oct  4 15:53:32 2020
 ************************************************************************/

#include <stdio.h>

int step(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    return step(n - 2) + step(1) * step(n - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        i == 1 || printf(" ");
        printf("%d", step(i));
    }
    printf("\n");
    return 0;
}
