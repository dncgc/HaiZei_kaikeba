/*************************************************************************
	> File Name: 139.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 15 Sep 2020 04:21:08 PM CST
 ************************************************************************/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i < 2 * n; i++) {
        if (i <= n) {
            for (int j = 0; j < n + i; j++) {
                if (j >= n - i) printf("A");
                else printf(" ");
            }
            printf("\n");
        } else {
            for (int j = 0; j < 3 * n - i; j++) {
                if (j >= i - n) printf("A");
                else printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}
