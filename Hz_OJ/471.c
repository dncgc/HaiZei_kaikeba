/*************************************************************************
	> File Name: 471.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 25 Dec 2020 09:01:32 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>

char num1[105], num2[105];
int n1[105], n2[105], ans[10005];

int main() {
    scanf("%s%s", num1, num2);
    n1[0] = strlen(num1);
    n2[0] = strlen(num2);
    ans[0] = n1[0] + n2[0] - 1;
    for (int i = n1[0] - 1, j = 1; i >= 0; i--,j++) {
        n1[j] = num1[i] - '0';
    }
    for (int i = n2[0] - 1, j = 1; i >= 0; i--,j++) {
        n2[j] = num2[i] - '0';
    }
    for (int i = 1; i <= n1[0]; i++) {
        for (int j = 1; j <= n2[0]; j++) {
            ans[i + j - 1] += n1[i] * n2[j];
        }
    }
    for (int i = 1; i <= ans[0]; i++) {
        if (ans[i] > 9) {
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
            if (i == ans[0]) {
                ans[0] += 1;
            }
        }
    }
    for (int i = ans[0]; i > 0; i--) {
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}
