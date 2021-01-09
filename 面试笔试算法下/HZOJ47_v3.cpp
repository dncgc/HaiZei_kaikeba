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
int dp[MAX_V + 5];


int main() {
    int V, n, v, w;
    cin >> V >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v >> w;
        for (int j = V; j >= v; j--) {
            dp[j] = max(dp[j], dp[j - v] + w);
        }
    }
    cout << dp[V] << endl;
    return 0;
}
