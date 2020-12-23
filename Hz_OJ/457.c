/*************************************************************************
	> File Name: 457.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon Oct  5 17:15:00 2020
 ************************************************************************/

#include <stdio.h>
#define abs(a) (a > 0 ? a : -a);
#define swap(a, b) {\
    __typeof(a) _a = a;\
    a = b; b = _a;\
}

int is_jolly(int *arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (arr[i - 1] == i) continue;
        return 0;
    }
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);
    int num[n - 1], pre, cur;
    for (int i = 0; i < n; ++i) {
        if (!i) {
            scanf("%d", &pre);
            continue;
        }
        scanf("%d", &cur);
        num[i - 1] = abs((cur - pre));
        pre = cur;
    }
    if (is_jolly(num, n - 1)) printf("Jolly\n");
    else printf("Not jolly\n");
    return 0;
}
