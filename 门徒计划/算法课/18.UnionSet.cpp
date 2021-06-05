/*************************************************************************
	> File Name: 18.UnionSet.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 29 Apr 2021 09:52:29 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class UnionSet {
public:
    int *fa, n;
    UnionSet(int n) : n(n) {
        fa = new int[n + 1];
        for (int i = 0; i <= n; i++) {
            fa[i] = i;
        }
    }
    int get(int x) {
        return fa[x] = (fa[x] == x ? x : get(fa[x]));
    }
    void merge(int a, int b) {
        fa[get(a)] = get(b);
        return ;
    }
};

int main() {
    return 0;
}
