/*************************************************************************
	> File Name: 150.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 17 Sep 2020 06:30:58 PM CST
 ************************************************************************/

#include <stdio.h>

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int mat[n][m];
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j++)
            scanf("%d", &mat[i][j]);
    }
    for (int j = 0; j < m; j++) {
        for (int i = n - 1; i >= 0; i--) {
            i == n - 1 || printf(" ");
            printf("%d", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}
