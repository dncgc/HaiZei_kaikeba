/*************************************************************************
	> File Name: 70_my.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat Sep 12 21:25:12 2020
 ************************************************************************/

#include <stdio.h>

int is_uglynum(int n) {
    while (n % 2 == 0) n /= 2;
    while (n % 3 == 0) n /= 3;
    while (n % 5 == 0) n /= 5;
    if (n == 1) return 1;
    else return 0;
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        if (is_uglynum(i)) printf("%d\n", i);
    }
    return 0;
}
