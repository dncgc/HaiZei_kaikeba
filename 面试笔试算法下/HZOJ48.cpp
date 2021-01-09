/*************************************************************************
	> File Name: HZOJ48.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 09 Jan 2021 03:50:25 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
int dp[10005];

int main() {
    int V, n, v, w;
    cin >> n >> V;
    for (int i = 1; i <= n; i++) {
        cin >> v >> w;
        for (int j = v; j <= V; j++) {
            dp[j] = max(dp[j], dp[j - v] + w);
        }
    }
    cout << dp[V] << endl;
    return 0;
}
