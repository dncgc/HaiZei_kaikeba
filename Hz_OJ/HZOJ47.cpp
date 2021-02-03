/*************************************************************************
	> File Name: HZOJ47.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 03 Feb 2021 08:05:31 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_V 10000

int V, n, dp[MAX_V + 5];

int main() {
    int v, w;
    scanf("%d%d", &V, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &v, &w);
        for (int j = V; j >= v; j--) {
            dp[j] = max(dp[j - v] + w, dp[j]);
        }
    }
    printf("%d\n", dp[V]);
    return 0;
}
