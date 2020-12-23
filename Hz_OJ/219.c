/*************************************************************************
	> File Name: 219.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 30 Sep 2020 03:20:40 PM CST
 ************************************************************************/

#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort_print(int *arr, int len, int l1, int r1, int l2, int r2) {
    int k = 0;
    for (int i = l1; i < r1; ++i) {
        for (int j = l1; j < r1 - k; ++j) {
            if (arr[j] > arr[j + 1]) swap(arr + j, arr + j + 1);
        }
        ++k;
    }
    k = 0;
    for (int i = l2; i < r2; ++i) {
        for (int j = l2; j < r2 - k; ++j) {
            if (arr[j] < arr[j + 1]) swap(arr + j, arr + j + 1);
        }
        ++k;
    }
    for (int i = 0; i < len; ++i) {
        i && printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, l1, r1, l2, r2;
    scanf("%d%d%d%d%d", &n, &l1, &r1, &l2, &r2);
    int num[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", num + i);
    }
    sort_print(num, n, l1 - 1, r1 - 1, l2 - 1, r2 - 1);
    return 0;
}
