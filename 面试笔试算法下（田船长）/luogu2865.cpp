/*************************************************************************
	> File Name: luogu2865.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon 01 Mar 2021 05:04:48 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct edge {
    int e, v, next;
};

edge edg[200005];
int n, m, edg_cnt, ans[100005], ans2[100005], head[100005], mark[100005];

void add_edg(int a, int b, int c) {
    edg[edg_cnt].e = b;
    edg[edg_cnt].v = c;
    edg[edg_cnt].next = head[a];
    head[a] = edg_cnt++;
}

int main() {
    memset(ans, 0x3f, sizeof(ans));
    memset(ans2, 0x3f, sizeof(ans2));
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 1 || b == 1) {
            ans2[1] = min(ans2[1], 2 * c);
        }
        add_edg(a, b, c);
        add_edg(b, a, c);
    }
    queue<int> que;
    que.push(1);
    ans[1] = 0;
    while (!que.empty()) {
        int temp = que.front();
        que.pop();
        mark[temp] = 0;
        for (int i = head[temp]; i != -1; i = edg[i].next) {
            int e = edg[i].e, v = edg[i].v;
            if (ans[e] > ans[temp] + v) { //根据最短更新最短
                ans2[e] = ans[e];
                ans[e] = ans[temp] + v;
                if (mark[e] == 0) {
                    mark[e] = 1;
                    que.push(e);
                }
            }
            //根据最短更新次短
            if (ans2[e] > ans[temp] + v && ans[temp] + v != ans[e]) {
                ans2[e] = ans[temp] + v;
                if (mark[e] == 0) {
                    mark[e] = 1;
                    que.push(e);
                }
            }
            //根据次短更新次短
            if (ans2[e] > ans2[temp] + v) {
                ans2[e] = ans2[temp] + v;
                if (mark[e] == 0) {
                    mark[e] = 1;
                    que.push(e);
                }
            }
        }
    }
    cout << ans2[n] << endl;
    return 0;
}
