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

int func(double x) {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (int)(num[i] / x);
    }
    return ans;
}

int main() {
    double l = 0.01, r = 0.0;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%lf", num + i);
        r = num[i] > r ? num[i] : r;
    }
    while ((r - l) > 0.01) {
        double mid = (int)(((l + r + 0.01) / 2) * 100) / 100.0;
        if (func(mid) >= k) l = mid;
        else r = mid - 0.01;
    }
    printf("%.2lf\n", l);
    return 0;
}
