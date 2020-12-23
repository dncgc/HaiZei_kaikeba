/*************************************************************************
	> File Name: 215.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 29 Sep 2020 05:39:53 PM CST
 ************************************************************************/

#include <stdio.h>

struct Grade {
    char name[15];
    int score[4]; 
    int total;
};

void swap(struct Grade *a, struct Grade *b) {
    struct Grade temp = *a;
    *a = *b;
    *b = temp;
}

void top_three_print(struct Grade *grade, int n) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (grade[j].total > grade[j + 1].total) swap(grade + j, grade + j + 1);
        }
    }
    for (int i = n - 1; i > n - 4; --i) {
        printf("%s\n", grade[i].name);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    struct Grade grade[n];
    for (int i = 0; i < n; ++i) {
        scanf("%s%d%d%d%d", grade[i].name, &grade[i].score[0], &grade[i].score[1],
              &grade[i].score[2], &grade[i].score[3]);
        grade[i].total = 0;
        for (int j = 0; j < 4; ++j) grade[i].total += grade[i].score[j];
    }
    top_three_print(grade, n);
    return 0;
}
