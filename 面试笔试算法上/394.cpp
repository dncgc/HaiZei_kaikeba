/*************************************************************************
	> File Name: 394.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 01 Jan 2021 06:54:33 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

int l, n, m, num[50005];

int func(int x) {
    int ans = 0, temp = num[0];
    for (int i = 1; i <= n; i++) {
        if (num[i] - temp >= x && num[n + 1] - num[i] >= x) {
            ans++;
            temp = num[i];
        }
    }
    return ans;
}

int main() {
    scanf("%d%d%d", &l, &n, &m);
    int ll = l, rr = l;
    for (int i = 1; i <= n ; i++) {
        scanf("%d", num + i);
        ll = (num[i] - num[i - 1]) < ll ? (num[i] - num[i - 1]) : ll;
    }
    num[n + 1] = l;
    while (ll != rr) {
        int mid = (ll + rr + 1) >> 1;
        if (func(mid) >= (n - m)) {
            ll = mid;
        } else {
            rr = mid - 1;
        }
    }
    printf("%d\n", ll);
    return 0;
}
