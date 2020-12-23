/*************************************************************************
	> File Name: 198.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 24 Sep 2020 11:18:48 AM CST
 ************************************************************************/

#include <stdio.h>
#define BIG 1000000007

/*int mod(int n, int m) {
    return n < m ? n : mod(n -m, m);
}*/

int faboncci_mod_big(int n) {
    int arr[n + 1];
    arr[1] = arr[2] = 1;
    for (int i = 3; i <= n; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
        while(arr[i] > BIG) arr[i] -= BIG;
    }
    return arr[n];
}

int main() {
    int n;
    scanf("%d", &n);
    //printf("%d\n", mod(faboncci(n), BIG));
    printf("%d\n", faboncci_mod_big(n));
    return 0;
}
