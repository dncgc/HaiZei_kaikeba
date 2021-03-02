/*************************************************************************
	> File Name: luogu1991.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 02 Mar 2021 08:38:25 PM CST
 ************************************************************************/

#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

struct edge {
    int s, e;
    double v;
    bool operator< (const edge &b) const {
        return this->v < b.v;
    }
};

int p, n, xy[505][2], my_union[505], edg_cnt, cnt;
edge edg[250005];
double ans;

int find_fa(int x) {
    if (my_union[x] == x) return x;
    return my_union[x] = find_fa(my_union[x]);
}

int main() {
    cin >> p >> n;
    for (int i = 1; i <= n; i++) {
        cin >> xy[i][0] >> xy[i][1];
        my_union[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1;  j <= n; j++) {
            int t1 = xy[i][0] - xy[j][0], t2 = xy[i][1] - xy[j][1];
            double t = sqrt(t1 * t1 + t2 * t2);
            edg[edg_cnt].s = i;
            edg[edg_cnt].e = j;
            edg[edg_cnt++].v = t;
        }
    }
    sort(edg, edg + edg_cnt);
    for (int i = 0; i < edg_cnt; i++) {
        int fa = find_fa(edg[i].s), fb = find_fa(edg[i].e);
        if (fa != fb) {
            ans = edg[i].v;
            my_union[fa] = fb;
            cnt++;
            if (n - p == cnt) break;
        }
    }
    printf("%.2f\n", ans);
    return 0;
}
