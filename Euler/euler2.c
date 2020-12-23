/*************************************************************************
	> File Name: euler2.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 23 Dec 2020 07:18:06 PM CST
 ************************************************************************/

#include <stdio.h>

int fib[1000];

int func(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (fib[n]) return fib[n];
    return fib[n] = func(n - 1) + func(n - 2);
}

int main() {
    /*
    long long ans = 0, a = 1, b = 2;
    for (b; b <= 4000000;) {
        if (b % 2 == 0) {
            ans += b;
        }
        b = a + b;
        a = b - a;
    }
    printf("%lld\n", ans);
    */
    int ans = 0;
    for (int i = 1,j = 0; j < 4000000; i++) {
        j = func(i);
        if (j & 1) continue;
        ans += j;
    }
    printf("%d\n", ans);
    return 0;
}
