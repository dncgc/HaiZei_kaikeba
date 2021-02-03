/*************************************************************************
	> File Name: 44.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 03 Feb 2021 01:46:03 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 1000000

int n, arr[MAX_N + 5];
int dp[MAX_N + 5];

int main() {
    int ans = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", arr + i);
        int t = 0;
        for (int j = i - 1; j >= 1; j--) {
            if (arr[j] < arr[i]) t = max(t, dp[j]);
        }
        dp[i] = t + 1;
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
    return 0;
}
