/*************************************************************************
	> File Name: 69.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu Sep 10 19:17:42 2020
 ************************************************************************/
//大量使用if else时间开销大
//月份天数固定，可用数组存储
//if else 可用三目运算符代替，效率比条件语句高
#include <stdio.h>

int month[13] = {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

int check1(int y, int m, int d) {
    if (m <= 0 || d <= 0 || m > 12) return 0;
    if ((y % 4 == 0 && y % 100) || y % 400 == 0) month[2] += 1;
    return d <= month[m];
}

int check(int y, int m, int d) {
    if (m <= 0 || d <= 0 || m > 12) return 0;
    if (m == 2) {
        if ((y % 4 == 0 && y % 100) || y % 400 == 0) {
            return d <= 29;
        } else {
            return d <= 28;
        }
    }
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m ==12) {
        return d <= 31;
    } else {
        return d <= 30;
    }
}

int main() {
    int y, m, d;
    scanf("%d%d%d", &y, &m, &d);
    //if (check(y, m, d)) {
    //    printf("YES\n");
    //} else {
    //    printf("NO\n");
    //}
    printf("%s\n", check1(y, m, d) ? "YES" : "NO");
    return 0;
}
