/*************************************************************************
	> File Name: prim.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 02 Mar 2021 06:58:49 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct node {
    int now, v;
    bool operator< (const node &b) const {
        return this->v > b.v;
    }
};

struct edge {
    int e, v, next;
};

edge edg[400005];
int n, m, ans, edg_cnt, head[5005],num[5005], cnt, mark[5005];
//num[i] 是在最小生成树中 i 与其它点相连的那条边的权值

void add_edg(int a, int b, int c) {
    edg[edg_cnt].e = b;
    edg[edg_cnt].v = c;
    edg[edg_cnt].next = head[a];
    head[a] = edg_cnt++;
}

int main() {
    memset(head, -1, sizeof(head));
    memset(num, 0x3f, sizeof(num));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add_edg(a, b, c);
        add_edg(b, a, c);
    }
    priority_queue<node> que;
    que.push((node){n, 0}); //可以任意点为起点
    num[n] = 0;
    while (!que.empty()) {
        node temp = que.top();
        que.pop();
        if (mark[temp.now] == 1) {
            continue;
        }
        mark[temp.now] = 1;
        ans += temp.v;
        cnt++;
        if (cnt == n) break;
        for (int i = head[temp.now]; i != -1; i = edg[i].next) {
            int e = edg[i].e, v = edg[i].v;
            if (mark[e] == 0 && num[e] > v) { //num数组不必要
                num[e] = v;
                que.push((node){e, v});
            }
        }
    }
    if (cnt == n) cout << ans << endl;
    else cout << "org" << endl;
    return 0; 
}
