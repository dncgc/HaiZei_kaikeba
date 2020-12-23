/*************************************************************************
	> File Name: 201.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 24 Sep 2020 03:09:13 PM CST
 ************************************************************************/

#include <stdio.h>

int search(int *arr, int len, int num) {
    for (int i = 0; i < len; i++) {
        if (arr[i] == num) return 1;
    }
    return 0;
}

void sort_print(int *arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        i && printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    int num[n];
    int m, j = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &m);
        if (i) {
            if (!search(num, j, m)) num[j++] = m;
            continue;
        }
        num[j++] = m;
    }
    printf("%d\n", j);
    sort_print(num, j);
    return 0;
}
