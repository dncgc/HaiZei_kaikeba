/*************************************************************************
	> File Name: 186.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 22 Sep 2020 10:38:50 AM CST
 ************************************************************************/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    int count = 0, distance = 0;
    while(distance < n) {
        distance += a[distance];
        ++count;
    }
    printf("%d\n", count);
    return 0;
}
