/*************************************************************************
	> File Name: 235_6_7.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 21 Jan 2021 11:51:29 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int n, m, ans[15], mark[15];

void print5(int cnt) {
    for (int i = 1; i <= cnt; i++) {
        i == 1 || cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return ;
}

void print6() {
    for (int i = 1; i <= m; i++) {
        i == 1 || cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return ;
}

void print7() {
    for (int i = 1; i <= n; i++) {
        i == 1 || cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return ;
}

void func5(int s, int cnt) {
    for (int i = s; i <= n; i++) {
        ans[cnt] = i;
        print5(cnt);
        func5(i + 1, cnt + 1);
    }
    return ;
}

void func6(int s, int cnt) {
    if (cnt == m + 1) {
        print6();
        return ;
    }
    for (int i = s; i <= n; i++) {
        ans[cnt] = i;
        func6(i + 1, cnt + 1);
    }
}

void func7(int cnt) {
    if (cnt == n + 1) {
        print7();
        return ;
    }
    for (int i = 1; i <= n; i++) {
        if (!mark[i]) {
            ans[cnt] = i;
            mark[i] = 1;
            func7(cnt + 1);
            mark[i] = 0;
        }
    }
}

int main() {
    cin >> n >> m;
    func5(1, 1);
    func6(1, 1);
    func7(1);
    return 0;
}
