/*************************************************************************
	> File Name: 202.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 25 Sep 2020 04:36:01 PM CST
 ************************************************************************/

#include <stdio.h>

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n;
    scanf("%d", &n);
    int height[n], number[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", height + i);
        number[i] = i + 1;
    }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (height[j] > height[j + 1]) {
                swap(height + j, height + j + 1);
                swap(number + j, number + j + 1);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        i && printf(" ");
        printf("%d", number[i]);
    }
    printf("\n");
    return 0;
}
