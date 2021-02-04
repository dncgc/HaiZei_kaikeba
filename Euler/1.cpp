/*************************************************************************
	> File Name: 1.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 04 Feb 2021 08:29:34 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    int ans = 0;
    for (int i = 3; i < 1000; i += 3) ans += i;
    for (int i = 5; i < 1000; i += 5) ans += i;
    for (int i = 15; i < 1000; i += 15) ans -= i;
    cout << ans << endl;
}
