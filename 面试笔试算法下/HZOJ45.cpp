/*************************************************************************
	> File Name: HZOJ45.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sun 27 Dec 2020 08:43:48 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 1000
string s1, s2;
int dp[MAX_N + 5][MAX_N + 5];


int main() {
    cin >> s1 >> s2;
    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
            }
        }
    }
    cout << dp[s1.size()][s2.size()] << endl;
    return 0;
}
