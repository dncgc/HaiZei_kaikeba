/*************************************************************************
	> File Name: HZOJ49.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 03 Feb 2021 08:43:46 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 100000

int V, n, dp[MAX_N + 5];

int main() {
    int v, w, s;
    scanf("%d%d", &V, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &v, &w, &s);
        for (int k = 1; s; k <<= 1) {
            if (k > s) k = s;
            s -= k;
            for (int j = V; j >= k * v; j--) {
                dp[j] = max(dp[j - k * v] + k * w, dp[j]);
            }
        }
    }
    printf("%d\n", dp[V]);
    return 0;
}
