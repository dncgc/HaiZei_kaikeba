/*************************************************************************
	> File Name: 236.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 19 Jan 2021 07:55:05 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int n, m, ans[15];

void p() {
    for (int i = 1; i <= m; i++) {
        i == 1 || cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return ;
}

void func(int s, int cnt, int left) {
    if (left == 0) {
        p();
        return ;
    }
    for (int i = s; i <= n; i++) {
        ans[cnt] = i;
        func(i + 1, cnt + 1, left - 1);
    }
    return ;
}

int main() {
    cin >> n >> m;
    func(1, 1, m);
    return 0;
}
