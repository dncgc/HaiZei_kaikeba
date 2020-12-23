/*************************************************************************
	> File Name: 199.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 24 Sep 2020 11:48:44 AM CST
 ************************************************************************/

#include <stdio.h>

int func(int *arr, int k, int m) {
    int result[k + 1];
    for (int i = 0; i <= k; i++) {
        result[i] = (i < 10 ? i :  arr[0] * result[i - 1] +  arr[1] * result[i - 2] + 
    arr[2] * result[i - 3] + arr[3] * result[i - 4] + arr[4] * result[i - 5] + 
    arr[5] * result[i - 6] + arr[6] * result[i - 7] + arr[7] * result[i - 8] + 
    arr[8] * result[i - 9] + arr[9] * result[i - 10]);
        while(result[i] > m) result[i] -= m;
    }
    return result[k];
}

int main() {
    int k, m;
    scanf("%d%d", &k, &m);
    int a[10];
    for (int i = 0; i < 10; i++) {
        scanf("%d", a + i);
    }
    printf("%d\n", func(a, k, m));
}
