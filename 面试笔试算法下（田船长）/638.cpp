/*************************************************************************
	> File Name: 638.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 12 Mar 2021 07:53:01 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct edge {
    int e, v, next;
};

edge edg[50000];
int n, m, head[1505], in_degree[1505], ans[1505];

int func() {
    int mark[1505] = {0, 1};
    queue<int> que;
    que.push(1);
    while (!que.empty()) {
        int temp = que.front();
        que.pop();
        if (temp == n) {
            return 0;
        }
        for (int i = head[temp]; i != -1; i = edg[i].next) {
            int e = edg[i].e;
            if (mark[e] == 0) {
                mark[e] = 1;
                que.push(e);
            }
        }
    }
    return 1;
}

int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edg[i].e = b;
        edg[i].v = c;
        edg[i].next = head[a];
        head[a] = i;
        in_degree[b]++;
    }
    if (func()) {
        cout << -1 << endl;
        return 0;
    }
    queue<int> que;
    for (int i = 1; i <= n; i++) {
        ans[i] = -2100000000;
        if (in_degree[i] == 0) {
            que.push(i);
        }
    }
    ans[1] = 0;
    while (!que.empty()) {
        int temp = que.front();
        que.pop();
        for (int i = head[temp]; i != -1; i = edg[i].next) {
            int e = edg[i].e, v = edg[i].v;
            if (ans[e] < ans[temp] + v) {
                ans[e] = ans[temp] + v;
            }
            in_degree[e]--;
            if (in_degree[e] == 0) {
                que.push(e);
            }
        }
    }
    cout << ans[n] << endl;

    return 0;
}
