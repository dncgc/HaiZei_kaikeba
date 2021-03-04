/*************************************************************************
	> File Name: 640.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 04 Mar 2021 06:57:57 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct edge {
    int e, next;
};

int n, m, head[5005], ans[5005], in_degree[5005], out_degree[5005], fin;
edge edg[500005];

int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edg[i].e = b;
        edg[i].next = head[a];
        head[a] = i;
        in_degree[b]++;
        out_degree[a]++;
    }
    queue<int> que;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            que.push(i);
            ans[i] = 1;
        }
    }
    while (!que.empty()) {
        int t = que.front();
        que.pop();
        for (int i = head[t]; i != -1; i = edg[i].next) {
            int e = edg[i].e;
            in_degree[e]--;
            ans[e] += ans[t];
            ans[e] %= 100000007;
            if (in_degree[e] == 0) {
                que.push(e);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (out_degree[i] == 0) {
            fin += ans[i];
            fin %= 100000007;
        }
    }
    cout << fin << endl;
    return 0;
}
