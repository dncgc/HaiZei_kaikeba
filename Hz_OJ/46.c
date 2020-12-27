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

int main() {
    scanf("%s", str);
    int n = strlen(str);
    for (int i = 1; i <= n; i++) {
        int flag = -1, cnt = 0;
        for (int j = i - 1; j >= 0; j--) {
            temp[cnt++] = str[j];
            if (j >= 0 && temp[cnt - 1] == temp[cnt - 2]) cnt -= 2;
            if (cnt == 0) {
                flag = j + 1;
                break;
            }
        }
        if (flag >= 0) dp[i] = dp[flag] + 1; 
        else dp[i] = dp[i - 1] + 1;
    }
    printf("%d\n", dp[n] - 1);
    return 0;
}
