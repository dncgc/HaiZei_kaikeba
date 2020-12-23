/*************************************************************************
	> File Name: 159.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 19 Sep 2020 10:59:45 AM CST
 ************************************************************************/

#include <stdio.h>

int main() {
    char ch, c;
    scanf("%c", &ch);
    int n = (ch - 'A') * 2 + 1;
    for (int i = ch; i >= 'A'; i--) {
        c = i;
        for (int j = 0; j < n - (ch - i); j++) {
            if (j >= ch - i) {
                j <= ch - 'A' ? printf("%c", c--) : printf("%c", ++c);
            }
            else printf(" ");
        }
        printf("\n");
    }
    return 0;
}
