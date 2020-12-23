/*************************************************************************
	> File Name: 217.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 30 Sep 2020 10:31:02 AM CST
 ************************************************************************/

#include <stdio.h>

/*void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}*/

void sort_print(int *score, int n) {
    /*for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (score[j] > score[j + 1]) swap(score + j, score + j + 1);
        }
        printf("%d\n", score[n - 1 - i]);
        if(i >= (n + 1) / 2 && score[n - 1 - i] != score[n - i]) {
            printf("%d %d\n", score[n - i], i);
            break;
        }
    }*/
    int count[101] = {0}, sum = 0;
    for (int i = 0; i < n; ++i) {
        ++count[score[i]];
    }
    for (int i = 100; i >= 0; --i) {
        sum += count[i];
        if (sum >= (n + 1) / 2) {
            printf("%d %d\n", i, sum);
            break;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int score[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", score + i);
    }
    sort_print(score, n);
    return 0;
}
