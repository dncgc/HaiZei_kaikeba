/*************************************************************************
	> File Name: 441.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sun Oct  4 15:30:13 2020
 ************************************************************************/

#include <stdio.h>

int distance(int x, int n) {
    int d = 6 - x > n ? n : (6 - x > 0 ? 6 - x : 0);
    if (8 - x >= n) return d * 2;
    while ((n - 8 + x) / 7) {
        d += 5;
        n -= 7;
    }
    d += (n - 8 + x < 5 ? n - 8 + x : 5);
    return d * 2;
}

int main() {
    int x, n;
    scanf("%d%d", &x, &n);
    printf("%d\n", distance(x, n));
    return 0;
}
