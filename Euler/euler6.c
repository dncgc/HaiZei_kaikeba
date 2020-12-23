/*************************************************************************
	> File Name: euler6.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 23 Dec 2020 08:03:45 PM CST
 ************************************************************************/

#include <stdio.h>

int main() {
    int qsum = 0, sumq = 0;
    for (int i = 1; i <= 100; i++) {
        qsum += i * i;
        sumq += i;
    }
    sumq *= sumq;
    printf("%d\n", sumq - qsum);
    return 0;
}
