/*************************************************************************
	> File Name: 235.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 19 Jan 2021 07:19:58 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int n, ans[15], cnt = 1;

void p() {
    for (int i = 1; i <= cnt; i++) {
        i == 1 || cout << " ";
        cout << ans[i];
    }
    cout << endl;
}

void func(int s) {
    for (int i = s; i <= n; i++) {
        ans[cnt] = i;
        p();
        cnt++;
        func(i + 1);
        cnt--;
    }
    return ;
}

int main() {
    cin >> n;
    func(1);
    return 0;
}
