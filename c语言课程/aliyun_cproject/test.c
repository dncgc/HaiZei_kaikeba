/*************************************************************************.
	> File Name: test.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 10 Sep 2020 04:31:35 PM CST
 ************************************************************************/

#include <stdio.h>
#include <string.h>

char *num_to_str(char *dst, int src) {
    sprintf(dst, "%d", src);
    return dst;
}

int main() {
    int i = 65;
    char str[10];
    //sprintf(str, "%d", i);
    char *str1;
    str1 = num_to_str(str, i);
    //printf("%s\n", num_to_str(str, i));
    printf("%s\n", str1);
    return 0;
}
