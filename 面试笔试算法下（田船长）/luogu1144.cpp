/*************************************************************************
	> File Name: luogu1144.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon 01 Mar 2021 04:31:45 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct edge {
    int e, v, next;
};

struct node {
    int num, dis;
    bool operator< (const node &b) const {
        return this->dis > b.dis;
    }
};

edge edg[4000005];
int n, m, edg_cnt, ans[1000005], ans_cnt[1000005], head[1000005];

void add_edg(int a, int b) {
    edg[edg_cnt].e = b;
    edg[edg_cnt].v = 1;
    edg[edg_cnt].next = head[a];
    head[a] = edg_cnt++;
}

int main() {
    memset(ans, 0x3f, sizeof(ans));
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i = 0; i < m ; i++) {
        int a, b;
        cin >> a >> b;
        add_edg(a, b);
        add_edg(b, a);
    }
    priority_queue<node> que;
    que.push((node){1, 0});
    ans[1] = 0;
    ans_cnt[1] = 1;
    while (!que.empty()) {
        node temp = que.top();
        que.pop();
        if (temp.dis > ans[temp.num]) {
            continue;
        }
        for (int i = head[temp.num]; i != -1; i = edg[i].next) {
            int e = edg[i].e;
            if (ans[e] > ans[temp.num] + 1) {
                ans[e] = ans[temp.num] + 1;
                ans_cnt[e] = ans_cnt[temp.num];
                que.push((node){e, ans[e]});
            } else if (ans[e] == ans[temp.num] + 1) {
                ans_cnt[e] += ans_cnt[temp.num];
                ans_cnt[e] %= 100003;
            }
        } 
    }
    for (int i = 1; i <= n; i++) {
            cout << ans_cnt[i] << endl;
    }
    return 0;
}
