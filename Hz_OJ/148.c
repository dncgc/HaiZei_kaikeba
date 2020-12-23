/*************************************************************************
	> File Name: 148.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 17 Sep 2020 05:49:08 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>

char *reverse(char *str) {
    char str_temp[strlen(str) + 1];
    int j = 0;
    for (int i = strlen(str) - 1; i >= 0; i--) {
        str_temp[j] = str[i];
        j++;
    } 
    str_temp[j] = '\0';
    strcpy(str, str_temp);
    return str;
}

int main() {
    char num[55] = {0};
    scanf("%s", num);
    printf("%s\n", reverse(num));
    return 0;
}
