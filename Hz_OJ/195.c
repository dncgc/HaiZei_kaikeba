/*************************************************************************
	> File Name: 195.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 24 Sep 2020 10:19:30 AM CST
 ************************************************************************/

#include <stdio.h>

int binary_search(int *arr, int len, int num) {
    if (num <= arr[0]) return arr[0];
    int left = 0, right = len - 1, mid = 0;
    while(left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] > num) right = mid - 1;
        else if (arr[mid] < num) left = mid + 1;
        else return arr[mid];
    }
    return arr[mid] < num ? arr[mid] : arr[mid - 1];
}

int main() {
    int n, m, number;
    scanf("%d%d", &n, &m);
    int num[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", num + i);
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d", &number);
        i && printf(" ");
        printf("%d", binary_search(num, n, number));
    }
    printf("\n");
    return 0;
}
