/*************************************************************************
	> File Name: 449_v2.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 26 Dec 2020 10:35:13 AM CST
 ************************************************************************/

#include <stdio.h>

int num[25][25];

int main() {
    int n;
    scanf("%d", &n);
    num[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            num[i][j] += num[i - 1][j - 1] + num[i - 1][j];
            j == 1 || printf(" ");
            printf("%d", num[i][j]);
        }
        printf("\n");
    }
    return 0;
}
