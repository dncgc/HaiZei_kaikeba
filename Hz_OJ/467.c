/*************************************************************************
	> File Name: 467.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed Oct  7 08:42:37 2020
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

int64_t factorial(int64_t n) {
    if (n == 1) return 1;
    else return n * factorial(n - 1);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%" PRId64  "\n", factorial(n));
    return 0;
}
