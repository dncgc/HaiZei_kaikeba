/*************************************************************************
	> File Name: 458.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon Oct  5 17:38:35 2020
 ************************************************************************/

#include <stdio.h>
#define swap(a, b) {\
    __typeof(a) _a = a;\
    a = b; b = _a;\
}

struct Stu {
    char name[20], gender[10];
    int year, month;
};

void struct_print(struct Stu s) {
    printf("%s %s %d %d\n", s.name, s.gender, s.year, s.month);
}

void sort_print(struct Stu *s, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (s[j].year < s[j + 1].year) {
                swap(s[j], s[j + 1]); 
                continue;
            }
            if (s[j].year == s[j + 1].year && s[j].month < s[j + 1].month)
                swap(s[j], s[j + 1]);
        }
    }
    for (int i = 0; i < n; ++i) {
        struct_print(s[i]);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    struct Stu stu[n];
    for (int i = 0; i < n; ++i) {
        scanf("%s%s%d%d", stu[i].name, stu[i].gender, &stu[i].year, &stu[i].month);
    }
    sort_print(stu, n);
    return 0;
}
