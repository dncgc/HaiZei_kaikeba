/*************************************************************************
	> File Name: luogu1629.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 26 Feb 2021 04:46:34 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct edge {
    int e, v, next;
};

edge edg1[100005], edg2[100005];
int n, m, head1[100005], head2[100005], ans1[100005], ans2[100005];
int mark[100005], ansfin;

void func(edge *edg, int *head, int *ans) {
    queue<int> que;
    que.push(1);
    while (!que.empty()) {
        int temp = que.front();
        que.pop();
        mark[temp] = 0;
        for (int i = head[temp]; i != -1; i = edg[i].next) {
            int e = edg[i].e, v = edg[i].v;
            if (ans[e] > ans[temp] + v) {
                ans[e] = ans[temp] + v;
                if (mark[e] == 0) {
                    mark[e] = 1;
                    que.push(e);
                }
            }
        }
    }
    return ;
}

void add_edg(edge *edg, int *head, int cnt, int s, int e, int v) {
    edg[cnt].e = e;
    edg[cnt].v = v;
    edg[cnt].next = head[s];
    head[s] = cnt;
}

int main() {
    memset(ans1, 0x3f, sizeof(ans1));
    memset(ans2, 0x3f, sizeof(ans2));
    memset(head1, -1, sizeof(head1));
    memset(head2, -1, sizeof(head2));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add_edg(edg1, head1, i, a, b, c);
        add_edg(edg2, head2, i, b, a, c);
    }
    ans1[1] = ans2[1] = 0;
    func(edg1, head1, ans1);
    func(edg2, head2, ans2);
    for (int i = 1; i <= n; i++) {
        ansfin += ans1[i] + ans2[i];
    }
    cout << ansfin << endl;
    return 0;
}
