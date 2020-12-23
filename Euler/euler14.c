/*************************************************************************
	> File Name: euler14.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 23 Dec 2020 08:42:11 PM CST
 ************************************************************************/

#include <stdio.h>

int num[10000000];

int func(long long n) {
    if (n == 1) return 1;
    if (n < 10000000 && num[n]) return num[n];
    int t;
    if (n & 1) {
        t = func(n * 3 + 1) + 1;
    } else {
        t = func(n / 2) + 1;
    }
    if (n < 10000000) {
        return num[n] = t;
    }
    return t;
}

int main() {
    int ans = 1;
    for (int i = 2; i < 1000000; i++) {
        if (func(i) > func(ans)) {
            ans = i;
        }
    }
    printf("%d\n", ans);
    return 0;
}
