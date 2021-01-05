/*************************************************************************
	> File Name: 82.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 05 Jan 2021 09:14:33 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

int n, m, height[1000005], l, r;

long long func(int x) {
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        if (height[i] <= x) continue;
        ans += height[i] - x;
    }
    return ans;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", height + i);
        r = max(r, height[i]);
    }
    while (l != r) {
        int mid = (l + r + 1) >> 1;
        if (func(mid) >= m) {
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    printf("%d\n", l);
    return 0;
}
