/*************************************************************************
	> File Name: 4.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 04 Feb 2021 09:02:45 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

bool is_palindrome(int n) {
    int t = n, ans = 0;
    while (t) {
        ans = ans * 10 + t % 10;
        t /= 10;
    }
    return ans == n;
}

int main() {
    int ans = 0;
    for (int i = 100; i < 1000; i++) {
        for (int j = i; j < 1000; j++) {
            int t = i * j;
            if (is_palindrome(t)) ans = max(ans, t);
        }
    }
    cout << ans << endl;
    return 0;
}
