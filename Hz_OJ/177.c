/*************************************************************************
	> File Name: 177.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 19 Sep 2020 06:03:49 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>

char *move(char *str) {
    int len = strlen(str);
    char temp[27];
    temp[0] = str[len-2];
    temp[1] = str[len-1];
    for (int i = 0; i < len - 2; i++) temp[2 + i] = str[i];
    for (int i = 0; i < len; i++) str[i] = temp[i];
    return str;
}

int main() {
    char str[27];
    scanf("%s", str);
    printf("%s\n", str);
    for (int i = 1; i < strlen(str); i++) {
        printf("%s\n", move(str));
    }
    return 0;
}
