/*************************************************************************
	> File Name: HZOJ47.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 09 Jan 2021 03:00:38 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 100
#define MAX_V 10000
int v[MAX_N + 5], w[MAX_N + 5];
int dp[MAX_N + 5][MAX_V + 5];


int main() {
    int V, n;
    cin >> V >> n;
    for (int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= V; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= v[i]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
            }
        }
    }
    cout << dp[n][V] << endl;
    return 0;
}
