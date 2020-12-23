/*************************************************************************
	> File Name: 156.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 18 Sep 2020 04:42:57 PM CST
 ************************************************************************/

#include <stdio.h>

int is_prime(int num) {
    for (int divisor = 3; divisor < (num / 2); divisor += 2) {
        if (num % divisor == 0) return 0;
    }
    return 1;
}

int is_compelte_square(int num) {
    int flag = 0, th_han = num / 100, ten_one = num % 100;
    for (int i = 1; i <= th_han / 2; i++) {
        if (i * i == th_han) {
            flag = 1;
            break;
        }
    }
    if (!flag) return 0;
    if (ten_one == 1) return 1;
    for (int i = 1; i <= ten_one / 2; i++) {
        if (i * i == ten_one) return 1;
    }
    return 0;
}

int main() {
    int a, b, count = 0;
    scanf("%d%d", &a, &b);
    a = (a % 2 ? a : a + 1);
    for (int i = a; i <= b; i += 2) {
        if (is_prime(i)) {
            if (is_compelte_square(i)) {
                if (count) printf(" ");
                printf("%d", i);
                count++;
            }
        }
    }
    printf("\n%d\n", count);
//    printf("%d%d\n", is_prime(a), is_compelte_square(a));
//    printf("%d%d\n", is_prime(b), is_compelte_square(b));
    return 0;
}
