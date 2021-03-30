/*************************************************************************
	> File Name: printf.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: 2020年09月16日 星期三 19时10分32秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int n, number;
    while (scanf("%d", &n) != EOF) {
        printf(" has %d digits!\n", printf("%d", n));
    }
//    number = printf("%d", n);
//    printf("\n%d\n", number);
    return 0;
}
