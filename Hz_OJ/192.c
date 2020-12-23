/*************************************************************************
	> File Name: 192.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 24 Sep 2020 09:17:21 AM CST
 ************************************************************************/

#include <stdio.h>
#include <math.h>
#define ERROR 0.01

double function(double x) {
    return x * exp(x);
}

double solution(double a) {
    if (!a) return 0.0;
    double left = -30.0, right = 30.0, mid = 0.0; 
    while (fabs(function(mid) - a) >= ERROR) {
        if (function(mid) > a) right = mid;
        else left = mid;
        mid = (right + left) / 2;
    }
    return mid;
}

int main() {
    int a;
    scanf("%d", &a);
    printf("%.4lf\n", solution(a));
    return 0;
}
