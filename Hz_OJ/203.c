/*************************************************************************
	> File Name: 203.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 25 Sep 2020 04:54:07 PM CST
 ************************************************************************/

#include <stdio.h>

int max(int *arr, int row, int col, int sel) {
    int m = *(arr + sel);
    for (int j = 1; j < row; ++j) {
        m = (*(arr + j * col + sel) > m ? *(arr + j * col + sel) : m);
    }
    return m;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int *arr, int number) {
    for (int i = 0; i < number - 1; ++i) {
        for (int j = 0; j < number - 1 - i; ++j) {
            if (*(arr + j) < *(arr + j + 1)) swap(arr + j, arr + j + 1);
        }
    }
}

void printf_average(int *arr, int number) {
    double sum = 0.0;
    int average, count = 0;
    for (int i = 0; i < number; i++) {
        i && printf(" ");
        printf("%d", *(arr + i));
        sum += *(arr + i);
    }
    printf("\n");
    average = (int)(sum / number + 0.5);
    printf("%d\n", average);
    for (int i = 0; i < number; i++) {
        if (*(arr + i) >= average) ++count;
    }
    printf("%d\n", count);
}

int main() {
    int M, N;
    scanf("%d%d", &M, &N);
    int height[M][N];
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", &height[i][j]);
        }
    }
    for (int i = 0; i < N; ++i) {
        printf("%d\n", max(&height[0][0], M, N, i));
    }
    sort(&height[0][0], M * N);
    printf_average(&height[0][0], M * N);
    return 0;
}
