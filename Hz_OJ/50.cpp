/*************************************************************************
	> File Name: 50.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 03 Feb 2021 08:58:04 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 50000
//#define MAX_N 10000000
int n, m; //dp[35][MAX_N + 5];
long long dp[35][MAX_N + 5];

int main() {
    scanf("%d%d", &n, &m);
    if (n == 1) {
        printf("%d\n", m);
        return 0;
    }
    for (int i = 1; i <= MAX_N; i++) dp[1][i] = i;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= MAX_N; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1] + 1;
        }
    }
    int k = 1;
    while (dp[n][k] < m) k++;
    printf("%d\n", k);
    /*
    for (int i = 1; i <= m; i++) dp[1][i] = i;
    for (int i = 2; i <= n; i++) {
        dp[i][1] = 1;
        dp[i][2] = 2;
        int k = 1;
        for (int j = 3; j <= m; j++) {
            //dp[i][j] = 0x7fff;
            while(dp[i - 1][k - 1] < dp[i][j - k]) k++;
            //for (int k = 1; k <= j; k++) {
            //dp[i][j] = min(dp[i][j], max(dp[i - 1][k - 1] + 1, dp[i][j - k] + 1));
            dp[i][j] = max(dp[i - 1][k - 1] + 1, dp[i][j - k] + 1);
            //}
        }
    }
    printf("%d\n", dp[n][m]);
    */
    return 0;
}
