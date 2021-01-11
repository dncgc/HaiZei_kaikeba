/*************************************************************************
	> File Name: 509.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 09 Jan 2021 11:16:51 AM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

struct Node {
    int money, ind;
};
Node node[505];
int m, n, mark[1005];

bool cmp(const Node &a, const Node &b) {
    if (a.money == b.money) return a.ind < b.ind;
    return a.money > b.money;
}

void read() {
    for (int i = 1; i <= n; i++) {
        scanf("%d", &node[i].ind);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &node[i].money);
    }
}

int main() {
    scanf("%d%d", &m, &n);
    read();
    sort(node + 1, node + n + 1, cmp);
    mark[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = node[i].ind; j >= 0; j--) {
            if (!mark[j]) {
                mark[j] = 1;
                break;
            }
            if (!j) m -= node[i].money;
        }
    }
    printf("%d\n", m);
    return 0;
}
