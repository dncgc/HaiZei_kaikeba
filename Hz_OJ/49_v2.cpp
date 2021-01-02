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
        for (int k = 1; s > 0; s -= k, k *= 2) {
            k = min(s, k);
            for (int j = V; j >= k * v; j--) {
                dp[j] = max(dp[j], dp[j - k * v] + k * w);
            }
        }
    }
    printf("%d\n", dp[V]);
    return 0;
}
