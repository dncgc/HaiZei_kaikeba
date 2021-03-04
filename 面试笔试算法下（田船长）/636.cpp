/*************************************************************************
	> File Name: 636.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 04 Mar 2021 08:00:06 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;

struct edge {
    int e, next;
};

int n, m, head[100005], in_degree[100005], ans[100005];
edge edg[200005];

int main() {
    memset(head, -1, sizeof(head));
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        edg[i].e = b;
        edg[i].next = head[a];
        head[a] = i;
        in_degree[b]++;
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
            ans[e] = max(ans[e], ans[t] + 1);
            if (in_degree[e] == 0) {
                que.push(e);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}
