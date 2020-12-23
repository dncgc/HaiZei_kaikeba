/*************************************************************************
	> File Name: euler11.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 23 Dec 2020 08:27:12 PM CST
 ************************************************************************/

#include <stdio.h>

int dirx[4] = {-1, 0, 1, 1};
int diry[4] = {1, 1, 1, 0};
int mat[30][30];

int main() {
    int ans = 0;
    for (int i = 5; i < 25; i++) {
        for (int j = 5; j < 25; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    for (int i = 5; i < 25; i++) {
        for (int j = 5; j < 25; j++) {
            for (int l = 0; l < 4; l++) {
                int result = mat[i][j];
                for (int m = 1; m < 4; m++) {
                    result *= mat[i + dirx[l] * m][j + diry[l] * m];
                }
                ans = ans < result ? result : ans;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
