/*************************************************************************
	> File Name: 50.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 03 Feb 2021 08:58:04 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

#define MAX_N 10000000
int n, m, dp[35][MAX_N + 5];

int main() {
    int ans
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= j; k++) {
                dp[i][j] = max(dp[i - 1][k], dp[i][m - k]);
            }
        }
    }
    return 0;
}
