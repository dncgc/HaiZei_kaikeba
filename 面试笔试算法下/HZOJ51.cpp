/*************************************************************************
	> File Name: HZOJ51.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sun 10 Jan 2021 07:09:00 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 1000
#define MOD_NUM 100007
int s[MAX_N + 5], top;
int c[MAX_N + 5][MAX_N + 5];
int f[MAX_N + 5];
int n, m;

void read() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> c[i][j];
            if (c[i][j]) c[i][j] += c[i - 1][j];
        }
    }
    return ;
}

int solve() {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        top = -1;
        s[++top] = 0;
        c[i][0] = -1;
        f[0] = 0;
        for (int j = 1; j <= m; j++) {
            while (top != -1 && c[i][s[top]] >= c[i][j]) --top;
            f[j] = c[i][j] * (j - s[top]) + f[s[top]];
            s[++top] = j;
            f[j] %= MOD_NUM;
            ans += f[j];
            ans %= MOD_NUM;
        }
    }
    return ans;
}

int main() {
    read();
    cout << solve() << endl;
    return 0;
}
