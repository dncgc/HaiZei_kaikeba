/*************************************************************************
	> File Name: 9.27_prime_linear.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: 2020年09月27日 星期日 18时43分28秒
 ************************************************************************/

#include <stdio.h>
#define MAX_N 100

int prime[MAX_N + 5];
//线性筛
void init() {
    for (int i = 2; i <= MAX_N; i++) { //m
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) { //p
            if (prime[j] * i > MAX_N) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return;
}

int main() {
    init();
    for (int i = 1; i < prime[0]; i++) {
        printf("%d\n", prime[i]);
    }
    return 0;
}
