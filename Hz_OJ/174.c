/*************************************************************************
	> File Name: 174.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 19 Sep 2020 05:16:39 PM CST
 ************************************************************************/

#include <stdio.h>

int main() {
    char *str = "%20";
    char ch;
    while (~scanf("%c", &ch)) {
        ch == ' ' ? printf("%s", str) : printf("%c", ch);
    }
    printf("\n");
    return 0;
}
