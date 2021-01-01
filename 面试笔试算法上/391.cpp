/*************************************************************************
	> File Name: 391.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 01 Jan 2021 04:17:15 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int n, m, num[100005];

int func(long long x) {
    int ans = 1;
    long long temp = 0;
    for (int i = 0; i < n; i++) {
        temp += num[i];
        if (temp > x) {
            ans++;
            i--;
            temp = 0;
        }
    }
    //printf("x = %d : %d\n", x, ans);
    return ans;
}

int main() { 
    long long l = 0, r = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", num + i);
        r += num[i];
        l = num[i] > l ? num[i] : l;
    }
    while (l != r) {
        long long mid = (l + r) >> 1;
        if (func(mid) > m) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    printf("%lld\n", l);
    return 0;
}
