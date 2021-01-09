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
int m, n, ans, ans2;

bool cmp(const Node &a, const Node &b) {
    return a.money > b.money;
}

bool cmp2(const Node &a, const Node &b) {
    if (a.ind == b.ind) return a.money > b.money;
    return a.ind < b.ind;
}

int main() {
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &node[i].ind);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &node[i].money);
    }
    sort(node + 1, node + n + 1, cmp);
    for (int i = 1, k = 1; i <= n; i++, k++) {
        int j = i + 1;
        if (!node[i].money) {
            k--;
            continue;
        }
        if (node[i].ind < k) {
            ans += node[i].money;
            k--;
            continue;
        }
        while(node[j].money == 0 && j < n) j++;
        if (node[j].ind < node[i].ind && node[j].ind >= k && 
            node[j].money != 0) {
            node[j].money = 0;
            i--;
        }
    }
    sort(node + 1, node + n + 1, cmp2);
    for (int i = 1, k = 1; i <= n; i++, k++) {
        if (node[i].ind < k) {
            ans2 += node[i].money;
            k--;
        }
    }
    printf("%d\n", (ans < ans2 ? m - ans: m - ans2));
    return 0;
}
