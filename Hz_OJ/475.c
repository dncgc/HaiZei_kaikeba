/*************************************************************************
	> File Name: 475.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 26 Dec 2020 10:53:52 AM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>

char num1[1005], num2[1005];
int n1[1005], n2[1005], ans[1005], n3[1005];

int compare(int *n1, int *n2) {
    if (n1[0] < n2[0]) {
        return -1;
    } else if (n1[0] > n2[0]) {
        return 1;
    } else {
        for (int i = n1[0]; i > 0; i--) {
            if (n1[i] == n2[i]) continue;
            if (n1[i] < n2[i]) return -1;
            else return 1;
        }
    }
    return 0;
}

void substract(int *n3, int *n1) {
    for (int i = 1; i <= n3[0] ; i++) {
        n3[i] -= n1[i];
        if (n3[i] < 0) {
            n3[i + 1] -= 1;
            n3[i] += 10;
        }
    }
    while (n3[0] > 0 && n3[n3[0]] == 0) --n3[0];
    return ;
}

void division(int *n1, int *n2) {
    for (int i = n2[0]; i > 0; i--) {
        for (int j = n3[0]; j > 0; j--) {
            n3[j + 1] = n3[j];
        }
        n3[1] = n2[i];
        n3[0]++;
        if (compare(n3, n1) < 0) ans[i] = 0;
        else {
            while (compare(n3, n1) >= 0) {
                substract(n3, n1);
                ans[i] += 1;
            }
        }
    }
    int flag = 0;
    for (int i = ans[0]; i > 0; i--) {
        if (flag == 0 && ans[i] == 0) continue;
        flag = 1;
        printf("%d", ans[i]);
    }
    if (!flag) printf("0");
    printf("\n");
    return ;
}

int main() {
    scanf("%s%s", num1, num2);
    n1[0] = strlen(num1);
    n2[0] = strlen(num2);
    ans[0] = n2[0];
    for (int i = 0, j = n1[0]; i < n1[0]; i++, j--) {
        n1[j] = num1[i] - '0';
    }
    for (int i = 0, j = n2[0]; i < n2[0]; i++, j--) {
        n2[j] = num2[i] - '0';
    }
    division(n1, n2);
    return 0;
}
