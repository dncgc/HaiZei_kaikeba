/*************************************************************************
	> File Name: 465.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue Oct  6 18:26:11 2020
 ************************************************************************/

#include <stdio.h>
#include <string.h>

char digit(char *num, int k) {
    if (k < 0 || k > strlen(num)) return '0';
    return num[strlen(num) - k];
}

int main() {
    int k;
    char num[40];
    scanf("%s%d", num, &k);
    printf("%c\n", digit(num, k));
    return 0;
}
