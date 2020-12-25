/*************************************************************************
	> File Name: 43.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 25 Dec 2020 11:17:14 PM CST
 ************************************************************************/

#include <stdio.h>

int num[1005][1005];

int main() {
    int n;
    scanf("%d", &n);
    //int num[n + 5][n + 5];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%d", &num[i][j]);
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            num[i][j] += (num[i + 1][j] > num[i + 1][j + 1] ? num[i + 1][j] : num[i + 1][j + 1]);
        }
    }
    printf("%d\n", num[0][0]);
    return 0;
}
