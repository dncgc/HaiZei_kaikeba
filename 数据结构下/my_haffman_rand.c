/*************************************************************************
	> File Name: my_haffman_rand.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon 18 Jan 2021 10:45:12 PM CST
 ************************************************************************/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    srand(time(0));
    int n = 26, sum = 0, arr[30];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
        sum += arr[i];
    }
    printf("%d\n", n);
    for (int i = 0; i < n; i++) {
        printf("%c %lf\n", 'A' + i, 1.0 * arr[i] / sum);
    }
    return 0;
}
