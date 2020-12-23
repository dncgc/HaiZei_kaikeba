/*************************************************************************
	> File Name: 193.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 24 Sep 2020 09:53:36 AM CST
 ************************************************************************/

#include <stdio.h>

void binary_search(int *arr, int len, int num) {
    int left = 0, right = len -1, mid = 0;
    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] > num) right = mid - 1;
        else if (arr[mid] < num) left = mid + 1;
        else {
            printf("Yes\n");
            return;
        }
    }
    printf("No\n");
}

int main() {
    int n, k, s;
    scanf("%d", &n);
    int num[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", num + i);
    }
    scanf("%d%d", &k, &s);
    binary_search(num, n, s - k);
    return 0;
}
