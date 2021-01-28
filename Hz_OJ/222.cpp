/*************************************************************************
	> File Name: 222.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 28 Jan 2021 04:31:12 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;
#define MAX_N 10000

#define L(a) a << 1
#define R(a) a << 1 | 1

struct Node {
    int max;
} tree[MAX_N << 2];
int n, m;
int arr[MAX_N + 5];

void update(int ind) {
    tree[ind].max = max(tree[L(ind)].max, tree[R(ind)].max);
    return ;
}

void build_tree(int ind, int l, int r) {
    if (l == r) {
        tree[ind].max = arr[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build_tree(L(ind), l, mid);
    build_tree(R(ind), mid + 1, r);
    update(ind);
    return ;
}

void modify(int ind, int l, int r, int x, int y) {
    if (l == r) {
        tree[ind].max = y;
        return ;
    }
    int mid = (l + r) >> 1;
    if (mid < x) {
        modify(R(ind), mid + 1, r, x, y);
    } else {
        modify(L(ind), l, mid, x, y);
    }
    update(ind);
    return ;
}

int query(int ind, int l, int r, int x, int y) {
    if (l >= x && r <= y) return tree[ind].max;
    int mid = (l + r) >> 1;
    int ans = INT_MIN;
    if (mid >= x) {
        ans = max(query(L(ind), l, mid, x, y), ans);
    }
    if (mid < y) {
        ans = max(query(R(ind), mid + 1, r, x, y), ans);
    }
    return ans;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", arr + i);
    }
    build_tree(1, 1, n);
    int a, b, c;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);
        switch (a) {
            case 1: {
                if (b > c) break;
                modify(1, 1, n, b, c);
            } break;
            case 2: {
                if (b > c) {
                    printf("-2147483648\n");
                    break;
                }
                printf("%d\n", query(1, 1, n, b, c));
            } break;
        }
    }
    return 0;
}
