/*************************************************************************
	> File Name: 46.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sun 27 Dec 2020 10:47:06 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#define MAX_N 500000

char str[MAX_N + 5], temp[MAX_N + 5];
int dp[MAX_N + 5];

int is_huiwen(char *str, int ls, int rs, char *temp) {
    for (int i = ls, j = 0; i <= rs; i++, j++) {
        if (str[i] != temp[j]) return 0;
    }
    return 1;
}

int main() {
    scanf("%s", str);
    int n = strlen(str);
    for (int i = 0; i < n; i++) {
        int flag = 0, cnt = 0;
        for (int j = i, k = 0; j >= 0; j--, k++) {
            temp[cnt++] = str[j];
            if (is_huiwen(str, j ,i, temp)) flag = j - 1;
        } 
        dp[i] = (flag == -1 ? 0 : dp[flag] + 1);
    }
    printf("%d\n", dp[n - 1]);
    return 0;
}
