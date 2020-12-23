/*************************************************************************
	> File Name: 208.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 26 Sep 2020 06:12:55 PM CST
 ************************************************************************/

#include <stdio.h>

int  select(int *arr, int len, int num) {
    int grade[101] = {0};
    for (int i = 0; i < len; i++) {
        ++grade[arr[i]];
    }
    for (int i = 100; i > 0; i--) {
        if (!grade[i]) continue;
        if (grade[i] < num) continue;
        return grade[i];
    }
}

int main() {
    int M, N;
    scanf("%d", &M);
    int score[M];
    for (int i = 0; i < M; i++) {
        scanf("%d", score + i);
    }
    scanf("%d", &N);
    printf("%d\n", select(score, M, N));
    return 0;
}
