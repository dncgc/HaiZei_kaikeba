/*************************************************************************
	> File Name: 141.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 15 Sep 2020 05:37:06 PM CST
 ************************************************************************/

#include <stdio.h>

int main() {
    int n, ch = 64;
    scanf("%d", &n);
    for (int i = 0; i < 2 * n + 1; i++) {
        if (i <= n) {
            for (int j = 0; j < 2 * n + 1 - i; j++) {
                if (j <= n) {
                    j >= i ? printf("%c", ++ch) : printf(" ");
                } else {
                    j >= i ? printf("%c", --ch) : printf(" ");
                }
            }
            printf("\n");
        } else {
            ch -= 2;
            for (int j = 0; j < i + 1; j++) {
                if (j <= n) {
                    j >= 2 * n - i ? printf("%c", ++ch) : printf(" ");
                } else {
                    j >= 2 * n - i ? printf("%c", --ch) : printf(" ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
