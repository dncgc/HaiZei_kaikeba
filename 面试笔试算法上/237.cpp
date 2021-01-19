/*************************************************************************
	> File Name: 237.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 19 Jan 2021 08:22:34 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int n, ans[15], mark[15];

void p() {
    for (int i = 1; i <= n; i++) {
        i == 1 || cout << " ";
        cout << ans[i];
    }
    cout << endl;
}

void func(int cnt) {
    if (cnt == n + 1) {
        p();
        return ;
    }
    for (int i = 1; i <= n; i++) {
        if (!mark[i]) {
            ans[cnt] = i;
            mark[i] = 1;
            func(cnt + 1);
            mark[i] = 0;
        }
    }
    return ;
}

int main() {
    cin >> n;
    func(1);
    return 0;
}
