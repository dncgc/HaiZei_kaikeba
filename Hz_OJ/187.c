/*************************************************************************
	> File Name: 187.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 22 Sep 2020 10:51:19 AM CST
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

int64_t moves(int n) {
    if (n == 1) return 1;
    else return 2 * moves(n - 1) + 1;
}

int64_t powers(int n) {
    if (n == 1) return 1;
    else return 2 * powers(n - 1) + n;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%" PRId64 " %" PRId64 "\n", moves(n), powers(n));
    return 0;
}
