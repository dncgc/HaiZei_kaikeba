/*************************************************************************
	> File Name: loop_struct.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: 2020年09月20日 星期日 18时17分35秒
 ************************************************************************/

#include <stdio.h>

int is_reverse(int n) { //base进制下是不是回文数，把10换为base
    if(n < 0) return 0;//unlikely()优化；
    int sum = 0, x = n;
    while (x) {
        sum = sum * 10 + x % 10;
        x /= 10;
    }
    return sum == n;
}

int is_prime(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n, digit = 0;
    scanf("%d", &n);
    do {
        digit += 1;
        n /= 10;
    } while (n);
    printf("has %d digits!\n", digit);
    //回文数
    int x = n;
    printf("%s\n", is_reverse(x) ? "Yes" : "No");
    printf("%s is prime.", is_prime(x) ? "Yes" : "No");
    return 0;
}
