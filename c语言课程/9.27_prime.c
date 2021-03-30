/*************************************************************************
	> File Name: 9.27_prime.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: 2020年09月27日 星期日 18时18分08秒
 ************************************************************************/
//最大最小素因子
#include <stdio.h>
#define MAX_N 100

int prime[MAX_N + 5];
void init() {
    for (int i = 2; i <= MAX_N; i++) {
        if (prime[i]) continue;
        prime[i] = i;
        for (int j = i; j <= MAX_N; j += i) {
            if (prime[j]) continue;
            prime[j] = i;
        }
    }
}

int main() {
    init();
    for (int i = 2; i <= MAX_N; i++) {
        printf("min_factor(%d) = %d\n", i, prime[i]);
    }
    return 0;
}
