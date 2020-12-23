/*************************************************************************
	> File Name: 452.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon Oct  5 15:27:02 2020
 ************************************************************************/

#include <stdio.h>
#define swap(a, b) {\
    __typeof(a) _a = a;\
    a = b; b = _a;\
}

int swap_times(int *arr, int n) {
    int count = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (arr[j] <= arr[j + 1]) continue;
            swap(arr[j], arr[j + 1]);
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    scanf("%d", &n);
    int num[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", num + i);
    }
    printf("%d\n", swap_times(num, n));
    return 0;
}
