/*************************************************************************
	> File Name: 39.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu Sep 10 19:08:54 2020
 ************************************************************************/

#include <stdio.h>

int main() {
    int begin, n;
    scanf("%d%d", &begin, &n);
    if (begin < 0) {
        begin = 0;
    } else if(begin % 2) {
        begin++;
    }
    while (n--) {
        printf("%d\n", begin);
        begin += 2;
    }
    return 0;
}
