/*************************************************************************
	> File Name: euler4.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 22 Dec 2020 06:54:37 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int func(int x) {
    int rev = 0, raw = x;
    while (x) {
        rev = rev * 10 + x % 10;
        x /= 10;
    }
    return rev == raw;
}

int main() {
    int ans = 0, a, b;
    for (int i = 100; i < 1000; i++) {
        for (int j = i; j < 1000; j++) {
            int t = i * j;
            if (func(t) && ans < t) {
                ans = t;
                a = i, b = j;
            }
        }
    }
    cout << a << " " << b << endl;
    cout << ans << endl;
    return 0;
}
