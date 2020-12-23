/*************************************************************************
	> File Name: 158.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 19 Sep 2020 10:41:14 AM CST
 ************************************************************************/

#include <stdio.h>

int main() {
    int n, num;
    scanf("%d", &n);
    num = n;
    for (int i = 0; i < n + 1; i++){
        for (int j = 0; j < 2 * n + 1 - i; j++) {
            (j == i || j == 2 * n - i) ?  printf("%d", num) : printf(" ");
        }
        num--;
        printf("\n");
    }
    num += 2;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < 2 * n + 1 - i; j++) {
            (j == i || j == 2 * n - i) ? printf("%d", num) : printf(" ");
        }
        num++;
        printf("\n");
    }
    return 0;
}
