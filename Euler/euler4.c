/*************************************************************************
	> File Name: euler4.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 23 Dec 2020 07:53:19 PM CST
 ************************************************************************/

#include <stdio.h>

int is_val(int n) {
    int ans = 0, raw = n;
    while(n) {
        ans = ans * 10 + n % 10;
        n /= 10;
    }
    return ans == raw;
}

int main() {
    int ans = 0, t;
    for (int i = 100; i < 1000; i++) {
        for (int j = i; j < 1000; j++) {
            t = j * i;
            if (is_val(t) && ans < t) {
                ans = t;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
