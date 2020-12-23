/*************************************************************************
	> File Name: 188.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 22 Sep 2020 11:53:58 AM CST
 ************************************************************************/

#include <stdio.h>

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    int num[1000001] = {0};
    num[0] = 1;
    num[1] = 1;
    for (int i = 2; i <= N; i++) {
        if (num[i] != 1) {
            for (int j = 2; j <= N / i; j++) {
                num[i * j] = 1;
            }
        }
    }
    for (int i = M; i <= N; i++) {
        if (num[i] == 0) printf("%d\n", i);
    }
}
