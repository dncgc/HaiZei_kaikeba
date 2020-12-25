/*************************************************************************
	> File Name: 78.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 25 Dec 2020 08:37:39 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>

char num1[110], num2[110];
int n1[110], n2[110], ans[110];

int main() {
    scanf("%s%s", num1, num2);
    n1[0] = strlen(num1);
    n2[0] = strlen(num2);
    ans[0] = n1[0] > n2[0] ? n1[0] : n2[0];
    for (int i = n1[0] - 1, j = 1; i >= 0; i--, j++) {
        n1[j] = num1[i] - '0';
    }
    for (int i = n2[0] - 1, j = 1; i >= 0; i--, j++) {
        n2[j] = num2[i] - '0';
    }
    for (int i = 1; i <= ans[0]; i++) {
        ans[i] += n1[i] + n2[i];
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
