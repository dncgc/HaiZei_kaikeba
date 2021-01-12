/*************************************************************************
	> File Name: HZOJ333.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 12 Jan 2021 08:00:47 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 500000
#define L(ind) (ind << 1)
#define R(ind) (ind << 1 | 1)
#define SUM(ind) tree[ind].sum
#define INMAX(ind) tree[ind].inmax
#define LMAX(ind) tree[ind].lmax
#define RMAX(ind) tree[ind].rmax
struct Data{
    int sum, inmax, lmax, rmax;
} _tree[(MAX_N << 2) + 5];
Data *tree = _tree + 1;
int n, m, flag;
int val[MAX_N + 5];

void UP(int a, int b, int c) {
    SUM(a) = SUM(b) + SUM(c);
    LMAX(a) = max(LMAX(b), SUM(b) + LMAX(c));
    RMAX(a) = max(RMAX(c), SUM(c) + RMAX(b));
    INMAX(a) = max(max(INMAX(b), INMAX(c)),RMAX(b) + LMAX(c));
    return ;
}

void build(int ind, int l, int r) {
    if (l == r) {
        SUM(ind) = INMAX(ind) = LMAX(ind) = RMAX(ind) = val[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(L(ind), l, mid);
    build(R(ind), mid + 1, r);
    UP(ind, L(ind), R(ind));
    return ;

}

void modify(int ind, int l, int r, int i, int x) {
    if (l == r) {
        SUM(ind) = INMAX(ind) = LMAX(ind) = RMAX(ind) = x;
        return ;
    }
    int mid = (l + r) >> 1;
    if (i <= mid) {
        modify(L(ind), l, mid, i, x);
    } else {
        modify(R(ind), mid + 1, r, i, x);
    }
    UP(ind, L(ind), R(ind));
    return ;
}

void query(int ind, int l, int r, int x, int y) {
    if (x <= l && r <= y) {
        if (flag) {
            tree[0] = tree[ind];
            flag = 0;
        } else {
            UP(-1, 0, ind);
            tree[0] = tree[-1];
        }
        return ;
    }
    int mid = (l + r) >> 1;
    if (x <= mid) {
        query(L(ind), l, mid, x, y);
    }
    if (y > mid) {
        query(R(ind), mid + 1, r, x, y);
    }
    return ;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    build(1, 1, n);
    for (int i = 0; i < m; i++) {
        int k, x, y;
        cin >> k >> x >> y;
        switch (k) {
            case 1: {
                if (x > y) swap(x, y);
                flag = 1;
                query(1, 1, n, x, y);
                cout << INMAX(0) << endl;
            } break;
            case 2: {
                modify(1, 1, n, x, y);
            } break;
        }
    }
    return ;
}

int main() {
    solve();
    return 0;
}
