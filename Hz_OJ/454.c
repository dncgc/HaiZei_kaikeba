/*************************************************************************
	> File Name: 454.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon Oct  5 15:50:30 2020
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
            if (arr[j] == arr[j + 1]) arr[j] = -1;
        }
    }
    int count = 0, flag = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] < 0) {
            ++count;
            continue;
        }
        if (flag == 0) printf("%d\n", n - count);
        flag && printf(" ");
        printf("%d", arr[i]);
        ++flag;
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    int num[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", num + i);
    }
    sort_print(num, n);
    return 0;
}
