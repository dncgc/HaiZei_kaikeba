/*************************************************************************
	> File Name: 466.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue Oct  6 18:33:01 2020
 ************************************************************************/

#include <stdio.h>

int is_reversenum(int num) {
    int reverse_num = 0, n = num;
    while (n) {
        reverse_num = reverse_num * 10 + n % 10;
        n /= 10;
    }
    return reverse_num == num;
}

int main() {
    int n, count = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        count = (is_reversenum(i) ? count + 1 : count);
    }
    printf("%d\n", count);
    return 0;
}
