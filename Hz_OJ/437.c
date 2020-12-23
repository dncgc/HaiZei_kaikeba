/*************************************************************************
	> File Name: 437.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sun Oct  4 11:16:51 2020
 ************************************************************************/

#include <stdio.h>

int number_of_pen(int a, int b) {
    double c = a + b / 10.0, price = 2.6;
    return (int)(c / price);
}

int main() {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d\n", number_of_pen(a,b));
    return 0;
}
