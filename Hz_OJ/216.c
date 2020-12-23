/*************************************************************************
	> File Name: 216.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 29 Sep 2020 06:16:12 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>

void delete_title(char *str) {
    char temp[55] = {0};
    int j = -1;
    for (int i = 3; i < strlen(str); ++i) {
        temp[++j] = str[i];
    }
    strcpy(str, temp);
}

void swap(char *str1, char *str2) {
    char temp[55] = {0};
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}

void sort_print(char name[][55], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (strcmp(name[j], name[j + 1]) > 0) swap(name[j], name[j + 1]);
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%s\n", name[i]);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    char name[n][55];
    for (int i = 0; i < n; ++i) {
        scanf("%s", name[i]);
        delete_title(name[i]);
    }
    sort_print(name, n);
    return 0;
}
