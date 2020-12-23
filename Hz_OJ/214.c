/*************************************************************************
	> File Name: 214.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 29 Sep 2020 05:30:13 PM CST
 ************************************************************************/

#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

double average(int *score, int n, int k) {
    double sum = 0.0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (score[j] < score[j + 1]) swap(score + j, score + j + 1);
        }
    }
    for (int i = 0; i < k; ++i) {
        sum += score[i];
    }
    return sum / k;
}

int main() {
    int N, K;
    scanf("%d", &N);
    int score[N];
    for (int i = 0; i < N; ++i) {
        scanf("%d", score + i);
    }
    scanf("%d", &K);
    printf("%.2lf\n", average(score, N, K));
    return 0;
}
