/*************************************************************************
	> File Name: 220.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 30 Sep 2020 04:11:12 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#define swap(a, b) {\
    __typeof(a) temp = a;\
    a = b;\
    b = temp;\
}

struct Student {
    char name[20];
    int score[5];
};

void sort_print(struct Student *stu, int n, int index) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (stu[j].score[index] > stu[j + 1].score[index]) swap(stu[j], stu[j + 1]);
            if (stu[j].score[index] == stu[j + 1].score[index] && strcmp(stu[j].name, stu[j + 1].name) < 0) swap(stu[j], stu[j + 1]);
        }
    }
    for (int i = n - 1; i > n - 5; --i) {
        i == n - 1 || printf(" ");
        printf("%s", stu[i].name);
    }
    printf("\n");
}
int main() {
    int n;
    scanf("%d", &n);
    struct Student stu[n];
    for (int i = 0; i < n; ++i) {
        scanf("%s%d%d%d%d", stu[i].name, stu[i].score, stu[i].score + 1, stu[i].score + 2,
              stu[i].score + 3);
        stu[i].score[4] = stu[i].score[0] + stu[i].score[1] + stu[i].score[2] + stu[i].score[3];
    }
    for (int i = 0; i < 5; ++i) {
        sort_print(stu, n, i);
    }
    return 0;
}
