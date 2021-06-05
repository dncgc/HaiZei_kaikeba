/*************************************************************************
	> File Name: 15.weighted_quick_union.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 29 Apr 2021 09:03:05 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class UnionSet {
public:
    int *fa, *size, n;
    UnionSet(int n) : n(n) {
        fa = new int[n + 1];
        size = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            fa[i] = i;
            size[i] = 1;
        }
    }
    int find(int x) {
        if (fa[x] == x) return x;
        return find(fa[x]);
    }
    void merge(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra == rb) return ;
        if (size[ra] < size[rb]) {
            fa[ra] = rb;
            size[rb] += size[ra];
        } else {
            fa[rb] = ra;
            size[ra] += size[rb];
        }
        return ;
    }
};

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    UnionSet u(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        switch (a) {
            case 1: u.merge(b, c); break;
            case 2: if (u.find(b) == u.find(c)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}
