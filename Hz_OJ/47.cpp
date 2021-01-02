/*************************************************************************
	> File Name: 47.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 02 Jan 2021 02:14:58 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

//int dp[2][10005];
int dp[10005];

int main() {
    int V, n, v, w;
    scanf("%d%d", &V, &n);
    /*
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &v, &w);
        for (int j = 1; j <= V; j++) {
            dp[i % 2][j] = dp[(i - 1) % 2][j];
            if (j >= v) {
                dp[i % 2][j] = max(dp[i % 2][j], dp[(i - 1) % 2][j - v] + w);
            }
        }
    }
    printf("%d\n", dp[n % 2][V]);
    */
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &v, &w);
        for (int j = V; j >= v; j--) {
            dp[j] = max(dp[j], dp[j - v] + w);
        }
    }
    printf("%d\n", dp[V]);
    return 0;
}
