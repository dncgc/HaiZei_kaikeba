/*************************************************************************
	> File Name: 211.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 29 Sep 2020 03:55:01 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>

void reverse(char *str) {
    int len = strlen(str), j = -1;
    char temp[45] = {0};
    for (int i = len - 1; i >= 0; i--) {
        temp[++j] = str[i];
    }
    strcpy(str, temp);
}

void swap(char *str1, char *str2) {
    char temp[45] = {0};
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}

void sort_print(char *name, int n, int col) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (strcmp(name + j * col, name + (j + 1) * col) > 0)
                swap(name + j * col, name + (j + 1) * col);
        }
    }
    for (int i = 0; i < n; ++i) {
        printf("%s\n", name + i * col);
    }
}

int main() {
    int N;
    scanf("%d", &N);
    char name[N][45];
    for (int i = 0; i < N; i++) {
        scanf("%s", name[i]);
        reverse(name[i]);
    }
    sort_print(&name[0][0], N, 45);
    return 0;
}
