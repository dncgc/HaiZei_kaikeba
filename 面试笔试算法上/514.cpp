/*************************************************************************
	> File Name: 514.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 08 Jan 2021 08:05:51 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int n, ans;
int num[15] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int func(int x) {
    if (x == 0) {
        return 6;
    }
    int t = 0;
    while (x) {
        t += num[x % 10];
        x /= 10;
    }
    return t;
}

int check(int a, int b) {
    int c = a + b;
    return func(a) + func(b) + func(c) + 4 == n;
}

int main() {
    cin >> n;
    for (int i = 0; i < 2000; i++) {
        for (int j = 0; j < 2000; j++) {
            if (check(i, j)) {
                ans++;
                cout << i << " + " << j << " = " << i + j << endl;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
