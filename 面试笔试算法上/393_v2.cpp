/*************************************************************************
	> File Name: 393.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 01 Jan 2021 04:48:02 PM CST
 ************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

double num[10005];
int n,k;

int func(int x) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (int)(num[i] * 100 / x);
    }
    return ans;
}

int main() {
    int l = 1, r = 0;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%lf", num + i);
        r = (int)(num[i] * 100) > r ? (int)(num[i] * 100) : r;
    }
    while (l != r) {
        int mid = (l + r + 1) >> 1;
        if (func(mid) >= k) l = mid;
        else r = mid - 1;
    }
    printf("%.2lf\n", l / 100.0);
    return 0;
}
