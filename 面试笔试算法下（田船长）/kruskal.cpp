/*************************************************************************
	> File Name: kruskal.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 02 Mar 2021 06:25:40 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct edge {
    int s, e, v;
    bool operator< (const edge &b) const {
        return this->v < b.v;
    }
};

edge edg[400005];
int n, m, ans, my_union[5005], cnt = 1;

int find_fa(int x) {
    if (my_union[x] == x) return x;
    return my_union[x] = find_fa(my_union[x]);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        my_union[i] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> edg[i].s >> edg[i].e >> edg[i].v;
    }
    sort(edg, edg + m);
    for (int i = 0; i < m; i++) {
        int fa = find_fa(edg[i].s), fb = find_fa(edg[i].e);
        if (fa != fb) {
            ans += edg[i].v;
            my_union[fa] = fb;
            cnt++;
            if (cnt == n) {
                break;
            }
        }
    }
    if (cnt == n) cout << ans << endl;
    else cout << "orz" << endl;
    return 0;
}
