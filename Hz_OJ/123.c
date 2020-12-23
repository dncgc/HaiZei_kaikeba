/*************************************************************************
	> File Name: 123.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon 14 Sep 2020 05:18:44 PM CST
 ************************************************************************/

#include <stdio.h>

int main() {
    int a, b, c, d;
    scanf("%d%d", &a, &b);
    scanf("%d%d", &c, &d);
    if ((c <= a && d >= b) || (a <= c && b >= d))
        printf("YES\n");
    else printf("NO\n");
    return 0;
}
