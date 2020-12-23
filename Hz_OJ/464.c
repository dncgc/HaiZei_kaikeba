/*************************************************************************
	> File Name: 464.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue Oct  6 18:10:35 2020
 ************************************************************************/

#include <stdio.h>

int is_leapyear(int year) {
    if ((year % 4 == 0 && year % 100) || year % 400 == 0) return 1;
    return 0;
}

void count_print(int x, int y) {
    int count = 0;
    for (int i = x; i <= y; ++i) {
        count = (is_leapyear(i) ? count + 1 : count); 
    }
    printf("%d\n", count);
}

int main() {
    int x, y;
    scanf("%d%d", &x, &y);
    count_print(x, y);
    return 0;
}
