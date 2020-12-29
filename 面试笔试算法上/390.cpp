/*************************************************************************
	> File Name: 390.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 29 Dec 2020 08:18:55 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int n, m, num[100005], l, r;

int func(int x) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += num[i] / x;
    }
    return s;
}

//二分答案
int bs() {
    while (l != r) {
        int mid = (l + r + 1) >> 1;
        int s = func(mid);
        if (s >= m) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    return r;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        r = max(r, num[i]);
    }
    cout << bs() << endl;

    return 0;
}
