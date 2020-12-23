/*************************************************************************
	> File Name: 197.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 24 Sep 2020 11:09:25 AM CST
 ************************************************************************/

#include <stdio.h>

int main() {
    int arr[10];
    for (int i = 0; i < 10; i++) {
        scanf("%d", arr + i);
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9 - i; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        i && printf(" ");
        printf("%d", arr[i]);
    }
    printf("\n");
    return 0;
}
