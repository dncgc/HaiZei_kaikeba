/*************************************************************************
	> File Name: luogu4826.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 12 Mar 2021 10:02:31 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

struct edge {
    long long s, e, v;
    bool operator< (const edge &b) const {
        return this->v > b.v;
    }
};

int my_union[2005], num[2005], now = 1;
long long n, m, ans;
edge edg[4000005];

int find_fa(int x) {
    if (my_union[x] == x) return x;
    return my_union[x] = find_fa(my_union[x]);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        my_union[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            edg[m].s = i;
            edg[m].e = j;
            edg[m].v = num[i] ^ num[j];
            m++;
        }
    }
    sort(edg, edg + m);
    for (int i = 0; i < m; i++) {
        int fa = find_fa(edg[i].s), fb = find_fa(edg[i].e);
        if (fa != fb) {
            ans += edg[i].v;
            my_union[fa] = fb;
            now++;
            if (now == n) break;
        }
    }
    cout << ans << endl;
    return 0;
}
