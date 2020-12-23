/*************************************************************************
	> File Name: 157.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 19 Sep 2020 10:07:56 AM CST
 ************************************************************************/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    char A = 64;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2 * n - 1 - i; j++) {
            if (j >= i) {
                j < n ? printf("%c", ++A) : printf("%c", --A);
            }
            else printf(" ");
        }
        printf("\n");
    }
    for (int i = n - 2; i >= 0; i--) {
        A -= 2;
        for (int j = 0; j < 2 * n - 1 -i; j++) {
            if (j >= i) {
                j < n ? printf("%c", ++A) : printf("%c", --A);
            }
            else printf(" ");
        }
        printf("\n");
    }
    return 0;
}
