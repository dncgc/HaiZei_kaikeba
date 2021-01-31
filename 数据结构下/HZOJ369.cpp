/*************************************************************************
	> File Name: HZOJ369.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sun 31 Jan 2021 06:09:23 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;
#define max_num 50000000666LL
typedef long long LL;

LL dp[20][2][2], pos[20];//i位数字中，包含的非魔鬼数的数量，后两位代表第i + 1、i+2 位是否是6

LL dfs(int i, int f1, int f2, int limit) {
    if (i == 0) return 1;
    if (!limit && dp[i][f1][f2]) return dp[i][f1][f2];
    LL up = limit ? pos[i] : 9;
    LL ret = 0;
    for (LL num = 0; num <= up; num++) {
        if (num == 6 && f1 && f2) continue;
        ret += dfs(i - 1, num == 6, f1, limit && num == up);
    }
    if (limit == 0) dp[i][f1][f2] = ret;
    return ret;
}

LL getNum(LL n) {
    memset(dp, 0, sizeof(dp));
    LL cnt = 0, y = n;
    while(n) {
        pos[++cnt] = n % 10;
        n /= 10;
    }
    return y - dfs(cnt, 0, 0, 1) + 1;
}

LL bs(LL l, LL r, LL x) {
    if (l == r) return l;
    LL mid = (l + r) >> 1;
    if (getNum(mid) < x) return bs(mid + 1, r, x);
    return bs(l, mid, x);
}

void solve() {
    int n;
    cin >> n;
    cout << bs(1, max_num, n) << endl;
    return ;
}

int main() {
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
