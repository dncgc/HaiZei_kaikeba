/*************************************************************************
	> File Name: 506.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 08 Jan 2021 10:55:26 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

struct Node {
    int val, ind;
};
Node node[35];
int n, add, addans;
double ans;

bool cmp(const Node &a, const Node &b) {
    return a.val < b.val;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &node[i].val);
        node[i].ind = i;
    }
    sort(node + 1, node + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        i == 1 || printf(" ");
        printf("%d", node[i].ind);
        add += node[i - 1].val;
        addans += add;
    }
    ans = double(addans) / n;
    printf("\n%.2lf\n", ans);
    return 0;
}
