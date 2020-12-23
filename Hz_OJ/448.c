/*************************************************************************
	> File Name: 448.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon Oct  5 14:36:12 2020
 ************************************************************************/

#include <stdio.h>

int num_location(int *num, int n, int number) {
    for (int i = 0; i < n; ++i) {
        if (num[i] == number) return i + 1;
    }
    return 0;
}

int main() {
    int n, number;
    scanf("%d", &n);
    int num[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", num + i);
    }
    scanf("%d", &number);
    printf("%d\n", num_location(num, n, number));
    return 0;
}
