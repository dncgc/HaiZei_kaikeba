/*************************************************************************
	> File Name: 116.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon 14 Sep 2020 11:55:06 AM CST
 ************************************************************************/

#include <stdio.h>

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void triangle_shape(int a, int b, int c) {
    if (a > b) swap(&a, &b);
    if (b > c) swap(&b, &c);
    if (a + b > c) {
        if (a * a + b * b > c * c) printf("acute triangle\n");
        else if (a * a + b * b == c * c) printf("right triangle\n");
        else printf("obtuse triangle\n");
    } else printf("illegal triangle\n");
  
}

int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    triangle_shape(a, b, c);
    return 0;
}
