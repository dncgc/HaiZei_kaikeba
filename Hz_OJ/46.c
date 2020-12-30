/*************************************************************************
	> File Name: 46.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sun 27 Dec 2020 10:47:06 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#define MAX_N 500000

char str[MAX_N + 5];
int dp[MAX_N + 5];

int is_huiwen(int l, int r) {
    for (int i = l, j = r; i <= j; i++, j--) {
        if (str[i] != str[j]) return 0;
    }
    return 1;
}

int main() {
    scanf("%s", str + 1);
    int n = strlen(str + 1);
    for (int i = 1; i <= n; i++) {
        dp[i] = is_huiwen(1, i) ? 0 : dp[i - 1] + 1;
        for (int j = 1; j < i; j++) {
            if (!is_huiwen(j + 1, i)) continue;
            dp[i] = dp[j] + 1 < dp[i] ? dp[j] + 1 : dp[i];
        }
    }
    printf("%d\n", dp[n]);
    return 0;
}
