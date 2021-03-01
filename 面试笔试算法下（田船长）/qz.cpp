/*************************************************************************
	> File Name: qz.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon 01 Mar 2021 01:50:56 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

char q[105], z[105];

void func(int ql, int qr, int zl, int zr) {
    if (ql > qr) {
        return ;
    }
    if (ql == qr) {
        cout << q[ql];
        return ;
    }
    char root = q[ql];
    int ind = zl;
    while (z[ind] != root) {
        ind++;
    }
    func(ql + 1, ql + ind - zl, zl, ind - 1);
    func(ql + ind - zl + 1, qr, ind + 1, zr);
    cout << root;
}

int main() {
    cin >> q >> z;
    func(0, strlen(q) - 1, 0, strlen(z) - 1);
    cout << endl;
    return 0;
}
