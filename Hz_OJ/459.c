/*************************************************************************
	> File Name: 459.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon Oct  5 18:02:58 2020
 ************************************************************************/

#include <stdio.h>

struct Stu {
    char name[20], gender;
    int age;
    double weight;
};

int main() {
    struct Stu s;
    scanf("%s %c%d%lf", s.name, &s.gender, &s.age, &s.weight);
    printf("%s %c %d %.1lf\n", s.name, s.gender, s.age, s.weight);
    return 0;
}
