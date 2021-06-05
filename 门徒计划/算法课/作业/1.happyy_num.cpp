/*************************************************************************
	> File Name: 1.happyy_num.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 19 Mar 2021 09:02:04 PM CST
 ************************************************************************/

#include <iostream>

int happ[100005];

int next(int n) {
    int ans = 0;
    while (n) {
        ans += (n % 10) * (n % 10);
        n /= 10;
    }
    return ans;
}

bool is_happy_num(int n) {
    int s = next(n), q = next(next(n));
    if (happ[n] || happ[s]) return true;
    while (s != q && !happ[q]) {
        s = next(s);
        q = next(next(q));
    }
    if (s == q) return false;
    happ[n] = 1;
    return true;
}

int main() {
    happ[1] = 1;
    int sum = 0;
    for (int i = 1; i <= 100000; i++) {
        if (is_happy_num(i)) sum += i;
    }
    std::cout << sum << std::endl;
    return 0;
}
