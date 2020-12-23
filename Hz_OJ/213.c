/*************************************************************************
	> File Name: 213.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 29 Sep 2020 04:57:33 PM CST
 ************************************************************************/

#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_print(int *score, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (score[j] < score[j + 1]) swap(score + j, score + j + 1);
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%d\n", score[i]);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    int score[N], count[6] = {0};
    for (int i = 0; i < N; i++) {
        scanf("%d", score + i);
        if (score[i] == 100) ++count[0];
        else if (score[i] >= 90) ++count[1];
        else if (score[i] >= 80) ++count[2];
        else if (score[i] >= 70) ++count[3];
        else if (score[i] >= 60) ++count[4];
        else ++count[5];
    }
    sort_print(score, N);
    for (int i = 0; i < 6; ++i) {
        i && printf(" ");
        printf("%d", count[i]);
    }
    printf("\n");
    return 0;
}
