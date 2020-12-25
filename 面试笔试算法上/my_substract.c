/*************************************************************************
	> File Name: 747.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 25 Dec 2020 10:03:44 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>

char num1[105], num2[105];
int n1[105], n2[105], ans[105];

int compare(char *num1, char *num2) {
    int n1 = strlen(num1), n2 = strlen(num2);
    if (n1 < n2) {
        return -1;
    } else if (n1 > n2) {
        return 1;
    } else {
        return strcmp(num1, num2);
    }
}

void subtract(char *num1, char *num2, int flag) {
    n1[0] = strlen(num1);
    n2[0] = strlen(num2);
    ans[0] = n1[0];
    for (int i = n1[0], j = 0; i > 0; i--, j++) {
        n1[i] = num1[j] - '0';
    }
    for (int i = n2[0], j = 0; i > 0; i--, j++) {
        n2[i] = num2[j] - '0';
    }
    for (int i = 1; i <= ans[0]; i++) {
        ans[i] += n1[i] - n2[i];
        if (ans[i] < 0) {
            ans[i + 1] -= 1;
            ans[i] += 10;
        }
    }
    if (flag == -1) printf("-");
    int flag0 = 0;
    for (int i = ans[0]; i > 0; i--) {
        if (flag0 == 0 && ans[i] == 0) continue;
        flag0 = 1;
        printf("%d", ans[i]);
    }
    printf("\n");
}

int main() {
    scanf("%s%s", num1, num2);
    if (compare(num1, num2) > 0) {
        subtract(num1, num2, 1);
    } else if (compare(num1, num2) < 0) {
        subtract(num2, num1, -1);
    } else {
        printf("0\n");
    }

    return 0;
}
