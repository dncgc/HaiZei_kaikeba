/*************************************************************************
	> File Name: 517.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 08 Jan 2021 08:29:00 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n / 3; i++) {
        for (int j = i; j <= (n - i) / 2; j++) {
            int t = n - i - j;
            if (i + j > t) {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return  0;
}
