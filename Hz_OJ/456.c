/*************************************************************************
	> File Name: 456.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon Oct  5 16:46:46 2020
 ************************************************************************/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int len = 0, num;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &num);
        len = len ^ num;
    }
    printf("%d\n", len);
    return 0;
}
