/*************************************************************************
	> File Name: 180.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon 21 Sep 2020 04:05:30 PM CST
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

uint64_t twopow(int n) {
    return (uint64_t)1 << n;// !!!要把1转换成64位
}
int main() {
    int n;
    scanf("%d", &n);
    printf("%" PRIu64 "\n", twopow(n));
    return 0;
}
