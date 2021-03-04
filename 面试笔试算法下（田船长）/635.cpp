/*************************************************************************
	> File Name: 635.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 04 Mar 2021 07:35:34 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct edge {
    int e, v, next;
};

int n, m, c[105], u[105], head[105], in_degree[105], out_degree[105];
edge edg[10005];

int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    queue<int> que;
    for (int i = 1; i <= n; i++) {
        cin >> c[i] >> u[i];
        if (c[i] != 0) {
            que.push(i);
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edg[i].e = b;
        edg[i].v = c;
        edg[i].next = head[a];
        head[a] = i;
        in_degree[b]++;
        out_degree[a]++;
    }
    while (!que.empty()) {
        int t = que.front();
        que.pop();
        for (int i = head[t]; i != -1; i = edg[i].next) {
            int e = edg[i].e, v = edg[i].v;
            if (c[t] > 0) {
                c[e] += c[t] * v;
            }
            in_degree[e]--;
            if (in_degree[e] == 0) {
                que.push(e);
                c[e] -= u[e];
            }
        }
    }
    int flag = 0;
    for (int i = 1; i <= n; i++) {
        if (out_degree[i] == 0 && c[i] > 0) {
            cout << i << " " << c[i] << endl;
            flag = 1;
        }
    }
    if (!flag) cout << "NULL" << endl;
    return 0;
}
