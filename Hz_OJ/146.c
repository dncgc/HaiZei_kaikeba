/*************************************************************************
	> File Name: 146.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 17 Sep 2020 05:16:00 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>

char* next_letter(char *str) {
    for (int i = 0; i < strlen(str); i++) {
        if ((str[i] >= 65 && str[i] < 90) || (str[i] >= 97 && str[i] < 122))
            str[i] += 1;
        else if (str[i] == 'Z')
            str[i] = 'A';
        else if (str[i] == 'z')
            str[i] = 'a';
    }
    return str;
    //printf("%s\n", str);
}

int main() {
    char str[55];
    scanf("%s", str);
    printf("%s\n", next_letter(str));
    return 0;
}
