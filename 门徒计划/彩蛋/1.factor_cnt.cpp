/*************************************************************************
	> File Name: 1.factor_cnt.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 05 Jun 2021 12:55:42 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 100

int prime[MAX_N + 5];
int f[MAX_N + 5];
int cnt[MAX_N + 5];

void init() {
    for (int i = 2; i <= MAX_N; i++) {
        if (!prime[i]) {
            prime[++prime[0]] = i;
            cnt[i] = 1;
            f[i] = 2;
        }
        for (int j = 1; j <= prime[0]; j++) {
            if (prime[j] * i > MAX_N) break;
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0) {
                cnt[i * prime[j]] = cnt[i] + 1;
                f[i * prime[j]] = f[i] / (cnt[i] + 1) * (cnt[i] + 2);
                break;
            } else {
                cnt[i * prime[j]] = 1;
                f[i * prime[j]] = f[i] * f[prime[j]];
            }
        }
    }
    return ;
}

int main() {
    init();
    for (int i = 2; i <= MAX_N; i++) {
        printf("f[%d] = %d\n", i, f[i]);
    }
    return 0;
}
