/*************************************************************************
	> File Name: 223.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 28 Jan 2021 05:41:07 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 10000

#define L(a) a << 1
#define R(a) a << 1 | 1

struct Node {
    long long sum;
    int flag;
} tree[MAX_N << 2];
int n, m, arr[MAX_N + 5];

void update(int ind) {
    tree[ind].sum = tree[L(ind)].sum + tree[R(ind)].sum;
    return ;
}

void down(int ind, int l, int r) {
    if (tree[ind].flag) {
        long long val = tree[ind].flag;
        int mid = (l + r) >> 1;
        tree[L(ind)].sum += val * (mid - l + 1);
        tree[L(ind)].flag += val;
        tree[R(ind)].sum += val * (r - mid);
        tree[R(ind)].flag += val;
        tree[ind].flag = 0;
    }
    return ;
}

void build_tree(int ind, int l, int r) {
    if (l == r) {
        tree[ind].sum = arr[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build_tree(L(ind), l, mid);
    build_tree(R(ind), mid + 1, r);
    update(ind);
    return ;
}

void modify(int ind, int l, int r, int x, int y, int val) {
    if (l >= x && y >= r) {
        tree[ind].flag += val;
        tree[ind].sum += val * (r - l + 1);
        return ;
    }
    down(ind, l, r);
    int mid = (l + r) >> 1;
    if (mid >= x) {
        modify(L(ind), l, mid, x, y, val);
    }
    if (mid < y) {
        modify(R(ind), mid + 1, r, x, y, val);
    }
    update(ind);
    return ;
}

long long query(int ind, int l, int r, int x, int y) {
    long long ans = 0;
    if (l >= x && y >= r) {
        return tree[ind].sum;
    }
    down(ind, l, r);
    int mid = (l + r) >> 1;
    if (mid >= x) {
        ans += query(L(ind), l, mid, x, y);
    }
    if (mid < y) {
        ans += query(R(ind), mid + 1, r, x, y);
    }
    return ans;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", arr + i);
    }
    build_tree(1, 1, n);
    for (int i = 0; i < m; i++) {
        int a, b, c, d;
        scanf("%d", &a);
        switch(a) {
            case 1: {
                scanf("%d%d%d", &b, &c, &d);
                modify(1, 1, n, b, c, d);
            } break;
            case 2: {
                scanf("%d%d", &b, &c);
                if (b > c) {
                    printf("0\n");
                    break;
                }
                printf("%lld\n", query(1, 1, n, b, c));
            } break;
        }
    }
    return 0;
}