/*************************************************************************
	> File Name: 137.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 15 Sep 2020 04:00:58 PM CST
 ************************************************************************/

#include <stdio.h>

int main() {
    int n, ch = 65;
    scanf("%d", &n);
    for (int i = n; i > 0; i--) {
        for (int j = i; j > 0; j--) {
            printf("%c", ch);
            ch++;
        }
        printf("\n");
    }
    return 0;
}
