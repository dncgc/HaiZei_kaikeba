/*************************************************************************
	> File Name: tuoposort.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 04 Mar 2021 06:22:30 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct edge {
    int e, next;
};

int n, m, in_degree[2005], head[2005], ans[2005], cnt;
edge edg[400005];

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
    }
    priority_queue<int, vector<int>, greater<int> > que;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            que.push(i);
        }
    }
    while (!que.empty()) {
        int t = que.top();
        que.pop();
        ans[cnt++] = t;
        for (int i = head[t]; i != -1; i = edg[i].next) {
            in_degree[edg[i].e]--;
            if (in_degree[edg[i].e] == 0) {
                que.push(edg[i].e);
            }
        }
    }
    if (cnt == n) {
        for (int i = 0; i < n; i++) {
            i == 0 || cout << " ";
            cout << ans[i];
        }
        cout << endl;
    } else {
        cout << "loop" << endl;
    }
    return  0;
}
