/*************************************************************************
	> File Name: 143.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 16 Sep 2020 11:07:36 AM CST
 ************************************************************************/

#include <stdio.h>

int thousand_hundred(int num) {
    return num / 100;
}

int ten_one(int num) {
    return num % 100;
}

int is_prime(int num) {
    if (num % 2 == 0) return 0;
    for (int divisor = 3; divisor < num / 2; divisor += 2) {
        if (num % divisor == 0) return 0;
    }
    return 1;
}

int is_complete_square(int num) {
    if (num == 1) return 1;
    for (int i = 1; i <= num / 2; i++) {
        if (i * i == num) return 1;
    }
    return 0;
}

int main() {
    int a, b, count = 0;
    scanf("%d%d", &a, &b);
    while (a % 6) a++;
    for (int i = a; i <= b; i += 6) {
        if (is_prime(thousand_hundred(i))) {
            if (is_complete_square(ten_one(i))) {
                if (count) printf(" ");
                printf("%d", i);
                count ++;
            }
        }
    }
    printf("\n%d\n", count);
    return 0;
}
