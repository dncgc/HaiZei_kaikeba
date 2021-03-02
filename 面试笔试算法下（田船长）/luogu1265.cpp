/*************************************************************************
	> File Name: luogu1265.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 02 Mar 2021 07:58:57 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
#include <cstdio>
#include <cmath>
using namespace std;

struct node {
    int now;
    double v;
    bool operator< (const node &b) const {
        return this->v > b.v;
    }
};

int n, xy[5005][2], mark[5005];
double ans, num[5005], cnt;

double func(int a, int b) {
    double t1 = xy[a][0] - xy[b][0], t2 = xy[a][1] - xy[b][1];
    return sqrt(t1 * t1 + t2 * t2);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> xy[i][0] >> xy[i][1];
        num[i] = 9999999999;
    }
    priority_queue<node> que;
    que.push((node){1, 0});
    num[1] = 0;
    while (!que.empty()) {
        node temp = que.top();
        que.pop();
        if (mark[temp.now] == 1) continue;
        mark[temp.now] = 1;
        ans += temp.v;
        cnt++;
        if (cnt == n) break;
        for (int i = 1; i <= n; i++) {
            if (i != temp.now && mark[i] == 0) {
                double v = func(temp.now, i);
                if (v < num[i]) {
                    num[i] = v;
                    que.push((node){i, v});
                }
            }
        }
    }
    printf("%.2f\n", ans);
    return 0;
}
