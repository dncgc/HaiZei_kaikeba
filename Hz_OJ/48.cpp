/*************************************************************************
	> File Name: 48.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 02 Jan 2021 02:45:31 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int dp[2][10005];

int main() {
    int n, V, v, w;
    scanf("%d%d", &n, &V);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &v, &w);
        for (int j = 1; j <= V; j++) {
            dp[i % 2][j] = dp[(i - 1) % 2][j];
            if (j >= v) {
                dp[i % 2][j] = max(dp[i % 2][j], dp[i % 2][j - v] + w);
            }
        }
    }
    printf("%d\n", dp[n % 2][V]);
    return 0;
}
