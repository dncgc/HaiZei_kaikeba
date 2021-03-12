/*************************************************************************
	> File Name: luogu1186.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 12 Mar 2021 10:42:12 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;

struct edge {
    int e, v, next;
};

edge edg[1000005];
int n, m, edg_cnt, head[1005], ans[1005], fin, from[1005];

void add_edg(int a, int b, int c) {
    edg[edg_cnt].e = b;
    edg[edg_cnt].v = c;
    edg[edg_cnt].next = head[a];
    head[a] = edg_cnt++;
}

void func(int f) {
    int mark[1005] = {0};
    memset(ans, 0x3f, sizeof(ans));
    queue<int> que;
    que.push(1);
    ans[1] = 0;
    while (!que.empty()) {
        int temp = que.front();
        que.pop();
        mark[temp] = 0;
        for (int i = head[temp]; i != -1; i = edg[i].next) {
            int e = edg[i].e, v = edg[i].v;
            if (ans[e] > ans[temp] + v) {
                ans[e] = ans[temp] + v;
                if (f == 1) {
                    from[e] = temp;
                }
                if (mark[e] == 0) {
                    mark[e] = 1;
                    que.push(e);
                }
            }
        }
    }
}

int main() {
    memset(head, -1, sizeof(head));
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add_edg(a, b, c);
        add_edg(b, a, c);
    }
    func(1);
    fin = ans[n];
    for (int i = n; i != 1; i = from[i]) {
        //i -> from[i], from[i] -> i
        int cnt1 = head[i], cnt2 = head[from[i]];
        while (edg[cnt1].e != from[i]) {
            cnt1 = edg[cnt1].next;
        }
        while (edg[cnt2].e != i) {
            cnt2 = edg[cnt2].next;
        }
        int v = edg[cnt1].v;
        edg[cnt1].v = edg[cnt2].v = 0x3f3f3f3f;
        func(0);
        fin = max(fin, ans[n]);
        edg[cnt1].v = edg[cnt2].v = v;
    }
    printf("%d\n", fin);
    return 0;
}
