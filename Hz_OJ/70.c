/*************************************************************************
	> File Name: 70.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu Sep 10 20:12:07 2020
 ************************************************************************/

#include <stdio.h>

int is_val(int n) {
    while (n % 2 == 0) n /= 2;
    while (n % 3 == 0) n /= 3;
    while (n % 5 == 0) n /= 5;
    return n == 1;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; j <= n; i++) {
        if (is_val(i)) printf("%d\n", i);
    }
    return 0;
}
