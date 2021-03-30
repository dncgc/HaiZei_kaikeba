/*************************************************************************
	> File Name: digui.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: 2020年09月20日 星期日 19时34分47秒
 ************************************************************************/

#include <stdio.h>

int factorial(int n) {
    return (n == 0 ? 1 : n * factorial(n - 1));
    /*if (n == 0) return 1;
    return n * factorial(n - 1);
    */
}

int main() {
    int n;
    while (~scanf("%d", &n)) {
        printf("fac(%d) = %d\n", n, factorial(n));
    }
//   scanf("%d", &n);
    printf("%d\n", factorial(n));
    return 0;
}
