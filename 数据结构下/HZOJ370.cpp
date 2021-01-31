/*************************************************************************
	> File Name: HZOJ370.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sun 31 Jan 2021 08:12:19 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int dp[11][90][90][90];
int base[90][11], pos[90];

void init_dp() {
    for (int i = 1; i < 90; i++) {
        base[i][0] = 1;
        for (int j = 1; j < 11; j++) {
            base[i][j] = base[i][j - 1] * 10 % i;
        }
    }
    for (int n = 0; n < 10; n++) {
        for (int k = 1; k < 90; k++) {
            dp[1][n][k][n % k] += 1;
        }
    }
    for (int n = 2; n <= 10; n++) {
        for (int i = 0; i < 90; i++) {
            for (int k = 1; k < 90; k++) {
                for (int j = 0; j < k; j++) {
                    dp[n][i][k][j] = 0;
                    for (int p = 0; p <= 9 && p <= i; p++) {
                        int jj = (j + k - (p * base[k][n - 1]) % k) % k;
                        dp[n][i][k][j] += dp[n - 1][i - p][k][jj];
                    }
                }
            }
        }
    }
    return ;
}

int dfs(int n, int i, int k, int j, int limit) {
    if (i < 0) return 0;
    if (n == 0) return i == 0 && j == 0;
    if (!limit) return dp[n][i][k][j];
    int up = limit ? pos[n] : 9;
    int ret = 0;
    for (int num = 0; num <= up && num <= i; num++) {
        int jj = (j + k - (num * base[k][n - 1]) % k) % k;
        ret += dfs(n - 1, i - num, k, jj, limit && num == up);
    }
    return ret;
}

int getNum(int n) {
    int cnt = 0;
    while (n) {
        pos[++cnt] = n % 10;
        n /= 10;
    }
    int ret = 0;
    for (int i = 1; i < 90; i++) {
        ret += dfs(cnt, i, i, 0, 1);
    }
    return ret;
}

int main() {
    init_dp();
    int l, r;
    while (cin >> l >> r) {
        cout << getNum(r) - getNum(l - 1) << endl;
    }
    return 0;
}
