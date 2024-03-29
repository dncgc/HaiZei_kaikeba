/*************************************************************************
	> File Name: 14.quick_union.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 29 Apr 2021 08:34:23 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class UnionSet {
public:
    int *boss, n;
    UnionSet(int n) : n(n) {
        boss = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            boss[i] = i;
        }
    }
    int find(int x) {
        if (boss[x] == x) return x;
        return find(boss[x]);
    }
    void merge(int a, int b) {
        int fa = find(a), fb = find(b);
        if (fa == fb) return ;
        boss[fa] = fb;
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
