/*************************************************************************
	> File Name: 142.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 15 Sep 2020 06:27:05 PM CST
 ************************************************************************/

#include <stdio.h>

void swap(int *a, int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int is_huiwen(int num) {
    int huiwen = 0, temp = num;
    while(temp) {
        huiwen = (huiwen * 10) + (temp % 10);
        temp /= 10;
    }
    if (huiwen == num) return 1;
    else return 0;
}

int is_prime(int num) {
    for (int divisor = 3; divisor <= num / 2; divisor += 2){
        if (num % divisor == 0) return 0;
    }
    return 1;
}

int main() {
    int a, b, flag = 0;
    scanf("%d%d", &a, &b);
    if (a > b) swap(&a, &b);
    if (a % 2 == 0) a += 1;
    for (int i = a; i <= b; i += 2) {
        if (is_huiwen(i)) {
            if (is_prime(i)) {
                if (flag) printf(" ");
                printf("%d", i);
                flag++;
            }
        }
    }
    printf("\n");
    return 0;
}
