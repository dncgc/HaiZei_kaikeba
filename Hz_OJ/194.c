/*************************************************************************
	> File Name: 194.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 24 Sep 2020 10:04:30 AM CST
 ************************************************************************/

#include <stdio.h>

void binary_search(int *arr, int len, int num) {
    int left, right = len - 1, mid = 0, index = -1;
    while(++index < len) {
        left = index + 1;
        while(left <= right) {
            mid = (left + right) / 2;
            if (arr[mid] > num - arr[index]) right = mid - 1;
            else if (arr[mid] < num - arr[index]) left = mid + 1;
            else {
                printf("Yes\n");
                return;
            }
        }
    }
    printf("No\n");
}

int main() {
    int n, s;
    scanf("%d", &n);
    int num[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", num + i);
    }
    scanf("%d", &s);
    binary_search(num, n, s);
    return 0;
}
