/*************************************************************************
	> File Name: 39_my.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat Sep 12 20:51:11 2020
 ************************************************************************/

#include <stdio.h>

int main() {
    int begin, n;
    scanf("%d%d", &begin, &n);
    if (begin < 0) begin = 0;
    if (begin % 2) begin += 1;
    while(n--) {
        printf("%d\n", begin);
        begin += 2;
    }
    return 0;
}
