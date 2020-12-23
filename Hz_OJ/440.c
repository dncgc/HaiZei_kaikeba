/*************************************************************************
	> File Name: 440.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sun Oct  4 14:58:30 2020
 ************************************************************************/

#include <stdio.h>

int is_equal(int i, int x) {
    int cnt = 0;
    while (i) {
        if (i % 10 == x) ++cnt;
        i /= 10;
    }
    return cnt;
}

int frequency(int num, int x) {
    int count = 0;
    for (int i = 1; i <= num; ++i) {
        count += is_equal(i, x);
    }
    return count;
}

int main() {
    int n, x;
    scanf("%d%d", &n, &x);
    printf("%d\n", frequency(n, x));
    return 0;
}
