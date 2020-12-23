/*************************************************************************
	> File Name: 178.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 19 Sep 2020 06:23:58 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>

char *symmetry(int n) {
    static char str[2 << 20];
    char ch = 'A', stemp[2 << (n - 1)];
    for (int i = 1; i <= n; i++) {
        if (n == 1) strcpy(str, "A");
        else {
            sprintf(stemp, "%s%c%s", str, ch + i - 1, str);
            strcpy(str, stemp);
        }
    }
    return str;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%s\n", symmetry(n));
    return 0;
}
