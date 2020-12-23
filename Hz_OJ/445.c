/*************************************************************************
	> File Name: 445.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sun Oct  4 16:55:48 2020
 ************************************************************************/

#include <stdio.h>

int pre_equal_behind(int *arr, int n) {
    int count = 0, pre, behind;
    for (int i = 0; i < n; ++i) {
        pre = behind = 0;
        for (int j = 0; j < n; ++j) {
            if (arr[j] <= arr[i]) continue;
            if (j < i) ++pre;
            else ++behind;
        }
        if (pre == behind) ++count;
    }
    return count;
}

int main() {
    int n;
    scanf("%d", &n);
    int height[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", height + i);
    }
    printf("%d\n", pre_equal_behind(height, n));
    return 0;
}
