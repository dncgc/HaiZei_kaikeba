/*************************************************************************
	> File Name: 121.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon 14 Sep 2020 04:22:56 PM CST
 ************************************************************************/

#include <stdio.h>

int main() {
    char a,b;
    scanf("%c %c", &a, &b);
    if (a == b) printf("TIE\n");
    else if ((a == 'O' && b == 'Y') || (a == 'Y' && b == 'H') || 
             (a == 'H' && b == 'O')) 
        printf("MING\n");
    else printf("LI\n");
    return 0;
}
