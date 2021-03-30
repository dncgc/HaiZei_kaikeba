/*************************************************************************
	> File Name: 9.25_prime.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: 2020年09月25日 星期五 20时43分40秒
 ************************************************************************/

#include <stdio.h>
#define MAX_N 100
int prime[MAX_N + 5];//函数外部默认清零

void init() {
    for (int i = 2; i <= MAX_N; i++) {
        if (prime[i]) continue;
        prime[++prime[0]] = i;
        for (int j = i * i; j <= MAX_N; j += i) {
            prime[j] = 1;
        }
    }
    return;
}

int main() {
    init();
    for (int i = 1; i <= prime[0]; i++) {
        printf("%d\n", prime[i]);
    }
    return 0;
}
