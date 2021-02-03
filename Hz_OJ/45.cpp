/*************************************************************************
	> File Name: 45.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 03 Feb 2021 02:03:57 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 1000

int dp[MAX_N + 5][MAX_N + 5];

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.size(); i++) {
        for (int j = 0; j < s2.size(); j++) {
            dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            if (s1[i] == s2[j]) {
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
            }
        }
    }
    cout << dp[s1.size()][s2.size()] << endl;
    return 0;
}
