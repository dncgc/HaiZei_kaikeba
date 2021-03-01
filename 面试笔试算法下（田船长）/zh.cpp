/*************************************************************************
	> File Name: zh.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon 01 Mar 2021 01:50:56 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

char z[105], h[105];

void func(int zl, int zr, int hl, int hr) {
    if (zl > zr) {
        return ;
    }
    if (zl == zr) {
        cout << z[zl];
        return ;
    }
    char root = h[hr];
    int ind = zl;
    while (z[ind] != root) {
        ind++;
    }
    cout << root;
    func(zl, ind - 1, hl, hl + ind - zl - 1);
    func(ind + 1, zr, hl + ind - zl, hr - 1);
}

int main() {
    cin >> z >> h;
    func(0, strlen(z) - 1, 0, strlen(h) - 1);
    cout << endl;
    return 0;
}
