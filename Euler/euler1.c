/*************************************************************************
	> File Name: euler1.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 23 Dec 2020 06:47:14 PM CST
 ************************************************************************/

#include <stdio.h>

int main() {
    /*
    int ans = 0;
    for (int i = 3; i < 1000; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            ans += i;
        }
    }
    printf("%d\n", ans);
    */
    int a3 = (3 + 999) * 333 / 2;
    int a5 = (5 + 995) * 199 / 2;
    int a15 = (15 + 990) * 66 / 2;
    printf("%d\n", a3 + a5 - a15);
    return 0;
}
