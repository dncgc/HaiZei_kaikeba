/*************************************************************************
	> File Name: 210.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 29 Sep 2020 11:40:56 AM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>

void swap(char *str1, char *str2) {
    char temp[15];
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}

void sort_print(char *arr, int len, int col) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - 1 - i; j++) {
            if (*(arr + col * j) > *(arr + col * (j + 1))) swap(arr + col * j, arr + col * (j + 1));
        }
    }
    for (int i = 0; i < len; i++) {
        i && printf(" ");
        printf("%s", arr + col * i);
    }
    printf("\n");
}

int main() {
    int N;
    scanf("%d", &N);
    char word[N][15];
    for (int i = 0; i < N; i++) {
        scanf("%s", word[i]);
    }
    sort_print(&word[0][0], N, 15);
    return 0;
}
