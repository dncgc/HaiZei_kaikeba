/*************************************************************************
	> File Name: HZOJ49.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 09 Jan 2021 04:05:38 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int dp[100005];

int main() {
    int V, n, v, w, s;
    cin >> V >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v >> w >> s;
        for (int k = 1; s; k *= 2) {
            if (k > s) k = s;
            s -= k;
            for (int j = V; j >= k * v; j--) {
                dp[j] = max(dp[j], dp[j - k * v] + k * w);
            }
        }
    }
    cout << dp[V] << endl;
    return 0;
}
