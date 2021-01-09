/*************************************************************************
	> File Name: HZOJ50_v2.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 09 Jan 2021 08:01:09 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 100
#define MAX_K 50000
long long dp[MAX_N + 5][MAX_K + 5];

int solve(int n, int m) {
    if (n == 1) return m;
    for (int i = 1; i <= MAX_K; i++) dp[1][i] = i;
    for (int i = 2; i <= n; i++) {
        for (int k = 1; k <= MAX_K; k++) {
            dp[i][k] = dp[i - 1][k - 1] + dp[i][k - 1] + 1;
        }
    }
    int k = 1;
    while (dp[n][k] < m) k++;
    return k;
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << solve(n, m) << endl;
    return 0;
}
