/*************************************************************************
	> File Name: HZOJ48.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 03 Feb 2021 08:30:52 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 10000

int n, V;
long long dp[MAX_N + 5];

int main() {
    int c, v;
    scanf("%d%d", &n, &V);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &c, &v);
        for (int j = c; j <= V; j++) {
            dp[j] = max(dp[j - c] + v, dp[j]);
        }
    }
    printf("%lld\n", dp[V]);
    return 0;
}
