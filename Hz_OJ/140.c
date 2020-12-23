/*************************************************************************
	> File Name: 140.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 15 Sep 2020 05:08:36 PM CST
 ************************************************************************/

#include <stdio.h>

int main() {
    int n, ch = 64;
    scanf("%d", &n);
    for (int i = 1; i < 2 * n; i++) {
        if (i <= n) {
            ch++;
            for (int j = 0; j < n + i - 1; j++) {
                j >= n - i ? printf("%c", ch) : printf(" ");
            }
            printf("\n");
        } else {
            ch--;
            for (int j = 0; j < 3 * n - i - 1; j++) {
                j >= i - n ? printf("%c", ch) : printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}
