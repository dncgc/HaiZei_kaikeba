/*************************************************************************
	> File Name: 450.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon Oct  5 15:06:13 2020
 ************************************************************************/

#include <stdio.h>
#define swap(a, b) {\
    __typeof(a) _a = a;\
    a = b; b = _a;\
}

void sort_print(int *arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
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
    int height[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", height + i);
    }
    sort_print(height, n);
    return 0;
}
