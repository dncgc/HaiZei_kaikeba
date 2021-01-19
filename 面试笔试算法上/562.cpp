/*************************************************************************
	> File Name: 562.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 19 Jan 2021 06:29:00 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        ans ^= t;
    }
    cout << ans << endl;
    return 0;
}
