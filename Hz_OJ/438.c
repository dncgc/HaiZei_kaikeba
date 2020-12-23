/*************************************************************************
	> File Name: 438.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sun Oct  4 11:22:48 2020
 ************************************************************************/

#include <stdio.h>

double electricity_bill(int a) {
    double fee1 = 0.4783, fee2 = 0.5283, fee3 = 0.7783;
    if (a <= 240) return a * fee1;
    if (a <= 400) return 240 * fee1 + (a - 240) * fee2;
    return 240 * fee1 + 160 * fee2 + (a - 400) * fee3;
}

int main() {
    int power;
    scanf("%d", &power);
    printf("%.1lf\n", electricity_bill(power));
    return 0;
}
