/*************************************************************************
	> File Name: 2.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 04 Feb 2021 08:49:00 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

#define MAX 4000000

int main() {
    int ans = 2, a = 1, b = 2, t = 0;
    while (t < MAX) {
        t = a + b;
        a = b;
        b = t;
        if (t % 2) continue;
        ans += t;
    }
    cout << ans << endl;
    return 0;
}
