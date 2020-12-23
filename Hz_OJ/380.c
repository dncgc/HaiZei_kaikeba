/*************************************************************************
	> File Name: 380.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon 26 Oct 2020 11:18:00 AM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>

void output_max(char (*str)[1005], int n) {
    char temp[1005] = {0}, index = 0;
    for (int i = 0; i < n; ++i) {
        if (strlen(str[i]) > strlen(temp)) {
            strncpy(temp, str[i], strlen(str[i]));
            index = i;
        }
        else if (strlen(str[i]) == strlen(temp) && strncmp(temp, str[i], strlen(temp) > 0)) {
            strncpy(temp, str[i], strlen(temp));
            index = i;
        }
    }
    printf("%d\n%s\n", index + 1, temp);
}

int main() {
    int N;
    scanf("%d", &N);
    char str[N][1005];
    for (int i = 0; i < N; ++i) {
        scanf("%s", str[i]);
    }
    output_max(str, N);
    return 0;
}
