/*************************************************************************
	> File Name: 446.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sun Oct  4 17:14:48 2020
 ************************************************************************/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int matrix[n][n], num = 1, m = n * n, row_sta = 0, row_end = n - 1, col_sta = 0, col_end = n - 1;
    while (1) {
        for (int i = col_sta; i <= col_end; ++i) {
            matrix[row_sta][i] = num;
            --m;
        }
        if (!m) break;
        ++row_sta;
        for (int i = row_sta; i <= row_end; ++i) {
            matrix[i][col_end] = num;
            --m;
        }
        if (!m) break;
        --col_end;
        for (int i = col_end; i >= col_sta; --i) {
            matrix[row_end][i] = num;
            --m;
        }
        if (!m) break;
        --row_end;
        for (int i = row_end; i >= row_sta; --i) {
            matrix[i][col_sta] = num;
            --m;
        }
        if (!m) break;
        ++col_sta;
        ++num;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            j && printf(" ");
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
