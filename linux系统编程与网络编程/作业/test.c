/*************************************************************************
	> File Name: test.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 24 Apr 2021 04:46:43 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>

int my_strlen(const char *str) {
    int len = 0, cnt = 0;
    while (str[len]) {
        cnt += (str[len] < 0); 
        len++;
    }
    return len - cnt / 3;
}

int main() {
    char str[256];
    while (~scanf("%s", str)) {
        int len = my_strlen(str);
        printf("%s\n", str);
        printf("The len is %d\n", len);
        while (len--) printf("t");
        printf("\n");
    }
    return 0;
}
