/*************************************************************************
	> File Name: 200.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 24 Sep 2020 01:13:50 PM CST
 ************************************************************************/

#include <stdio.h>

double function_sum(int *num, int *denom, int n) {
    num[0] = 4, denom[0] = 7;
    double sum = num[0] * 1.0 / denom[0];
    for (int i = 1; i < n; i++) {
        num[i] = denom[i - 1];
        denom[i] = num[i - 1] + denom[i - 1];
        sum += num[i] * 1.0 / denom[i];
    } 
    return sum;
}

int main() {
    int N;
    scanf("%d", &N);
    int numerator[N], denomiator[N];
    double sum = function_sum(numerator, denomiator, N);
    printf("%d/%d\n", numerator[N - 1], denomiator[N - 1]);
    printf("%.2lf\n", sum);
    return 0;
}
