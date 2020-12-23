/*************************************************************************
	> File Name: 184.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 22 Sep 2020 10:23:43 AM CST
 ************************************************************************/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int num = 1;
    for (int i = 0; i < n - 1; i++) {
        num = (num + 1) << 1;
    }
    printf("%d\n", num);
    return 0;
}
