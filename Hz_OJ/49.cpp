/*************************************************************************
	> File Name: 49.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 02 Jan 2021 03:31:21 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int dp[100005];

int main() {
    int V, n, v, w, s;
    scanf("%d%d", &V, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &v, &w, &s);
        for (int k = 1; k <= s; k++) {
            for (int j = V; j >= v; j--) {
                dp[j] = max(dp[j], dp[j - v] + w);
            }
        }
    }
    printf("%d\n", dp[V]);
    return 0;
}
