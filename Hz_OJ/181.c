/*************************************************************************
	> File Name: 181.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon 21 Sep 2020 04:53:03 PM CST
 ************************************************************************/

#include <stdio.h>

int main() {
    char ch;
    while(~scanf("%c", &ch)) {
        if (ch >= 65 && ch <= 90) ch += 32;
        else if (ch >= 97 && ch <= 122) ch -= 32;
        printf("%c", ch);
    }
    printf("\n");
    return 0;
}
