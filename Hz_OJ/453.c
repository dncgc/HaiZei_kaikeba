/*************************************************************************
	> File Name: 453.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon Oct  5 15:33:38 2020
 ************************************************************************/

#include <stdio.h>
#define swap(a, b) {\
    __typeof(a) _a = a;\
    a = b; b = _a;\
}

void sort_print(int *arr, int n, int k) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 -i; ++j) {
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
        }
    }
    int cnt = 1, index = 0;
    while (cnt < k && index < n - 1) {
        if (arr[++index] == arr[index - 1]) continue;
        ++cnt;
    }
    if (cnt < k) printf("NO RESULT\n");
    else printf("%d\n", arr[index]);
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int num[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", num + i);
    }
    sort_print(num, n, k);
    return 0;
}
