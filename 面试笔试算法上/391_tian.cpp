/*************************************************************************
	> File Name: 391_tian.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 05 Jan 2021 06:12:39 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

long long n, m, num[100005], l, r;

long long func2(long long x) {
    long long cnt = 0, now = 0;
    for (int i = 0; i < n; i++) {
        if (now + num[i] > x) {
            cnt++;
            now = num[i];
        } else if (now + num[i] == x) {
            cnt++;
            now = 0;
        } else {
            now += num[i];
        }
    }
    if (now > 0) {
        cnt++;
    }
    return cnt;
}

long long func() {
    while (l != r) {
        long long mid = (l + r) >> 1;
        long long s = func2(mid);
        if (s <= m) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}

int main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &num[i]);
        r += num[i];
        l = max(l, num[i]);
    }
    printf("%lld\n", func());
    return 0;
}
