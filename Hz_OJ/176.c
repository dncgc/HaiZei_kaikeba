/*************************************************************************
	> File Name: 176.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 19 Sep 2020 05:30:57 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int main() {
    char nv[1001] = {0};
    char lu[1001] = {0};
    scanf("%[^\n]s", nv);
    getchar();
    scanf("%[^\n]s", lu);
    getchar();
    int flag, count = 0;
    if (strlen(lu) > strlen(nv)) count = 0;
    else {
        for (int i = 0; i <= strlen(nv) - strlen(lu); i++) {
            flag = 1;
            for (int j = 0; j < strlen(lu); j++) {
                if (nv[i + j] ^ lu[j]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) count++;
        }
    }
    printf("%d\n", count);
    return 0;
}
