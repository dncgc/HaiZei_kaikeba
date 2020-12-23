/*************************************************************************
	> File Name: 461.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue Oct  6 09:07:35 2020
 ************************************************************************/

#include <stdio.h>

struct Stu {
    char type;
    char grade[10];
};

int str2num(char *str) {
    int i = 0, num = 0;
    while(str[i]) {
        num = num * 10 + (str[i] - '0');
        ++i;
    }
    return num;
}

void count_print(struct Stu *s, int n) {
    int count = 0, sum = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i].type == 'C') ++count;
        else sum += str2num(s[i].grade);
    }
    printf("%d %d\n", count, sum / (n - count));
}

int main() {
    int n;
    scanf("%d\n", &n);
    struct Stu stu[n];
    for (int i = 0; i < n; ++i) {
        scanf("%1s%s", &stu[i].type, stu[i].grade);
    }
    count_print(stu, n);
    return 0;
}
