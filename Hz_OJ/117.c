/*************************************************************************
	> File Name: 117.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon 14 Sep 2020 01:56:44 PM CST
 ************************************************************************/

#include <stdio.h>

int huiwen(int a) {
    int temp = 0, sum = 0;
    while(a) {
        temp = a % 10;
        sum = sum * 10  + temp;
        a /= 10;
    }
    return sum;
}

int main() {
    int a;
    scanf("%d", &a);
    if (a == huiwen(a)) printf("YES\n");
    else printf("NO\n");
    return 0;
}
