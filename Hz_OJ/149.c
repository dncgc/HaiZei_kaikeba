/*************************************************************************
	> File Name: 149.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 17 Sep 2020 06:21:05 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int last_letter_length(char *str) {
    int len = strlen(str), letter_count = 0;
    while (str[--len] != ' ') letter_count++;
    return letter_count;
}

int main() {
    char str[55] = {0};
    scanf("%[^\n]s", str);
    printf("%d\n", last_letter_length(str));
    return 0;
}
