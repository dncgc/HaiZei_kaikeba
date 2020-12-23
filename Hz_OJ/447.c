/*************************************************************************
	> File Name: 447.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sun Oct  4 17:37:03 2020
 ************************************************************************/

#include <stdio.h>

int is_luckynum(int n) {
    int flag = 0;
    while (n) {
        if (n % 10 == 4 || n % 10 == 7) {
            flag = 1;
            n /= 10;
            continue;
        }
        flag = 0;
        break;
    }
    return flag;
}

int main() {
    int n, flag = 0;
    scanf("%d", &n);
    int lucky[40] = {0}, index = -1;
    for (int i = 1; i <= n; ++i) {
        if (is_luckynum(i)) lucky[++index] = i;
    }
    for (int i = 0; i <= index; ++i) {
        if (n % lucky[i]) continue;
        flag = 1;
        printf("YES\n");
        break;
    }
    if (!flag) printf("NO\n");
    return 0;
}
