/*************************************************************************
	> File Name: 212.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 29 Sep 2020 04:46:19 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#define N 10
char name[N][25];

void swap(char *str1, char *str2) {
    char temp[25] = {0};
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}

void sort_print(char *name) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - 1 - i; ++j) {
            if (strcmp(name + j * 25, name + (j + 1) * 25) > 0)
                swap(name + j * 25, name + (j + 1) * 25);
        }
    }
    for (int i = 0; i < N; i++) {
        printf("%s\n", name + i * 25);
    }
}

int main() {
    for (int i = 0; i < N; i++) {
        scanf("%s", name[i]);
    }
    sort_print(&name[0][0]);
    return 0;
}
