/*************************************************************************
	> File Name: 185.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 22 Sep 2020 10:31:53 AM CST
 ************************************************************************/

#include <stdio.h>

int fibonacci(int n) {
    if (n == 1) return 1;
    if (n == 2) return 1;
    else return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", fibonacci(n));
    return 0;
}
