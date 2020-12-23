/*************************************************************************
	> File Name: 449.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon Oct  5 14:44:54 2020
 ************************************************************************/

#include <stdio.h>

void yanghui_print(int n) {
    int pre[n], temp[n];
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n; ++k) temp[k] = pre[k];
        for (int j = 0; j <= i; ++j) {
            j && printf(" ");
            if (!j || j == i) {
                printf("1");
                pre[j] = 1;
                continue;
            }
            printf("%d", temp[j - 1] + temp[j]);
            pre[j] = temp[j - 1] + temp[j];
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    yanghui_print(n);
    return 0;
}
