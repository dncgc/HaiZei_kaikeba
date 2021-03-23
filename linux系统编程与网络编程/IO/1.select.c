/*************************************************************************
	> File Name: 1.select.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 23 Mar 2021 07:30:14 PM CST
 ************************************************************************/

#include "head.h"

int main() {
    int age;
    fd_set rfds;
    struct timeval tv;
    tv.tv_sec = 5;
    tv.tv_usec = 0;
    FD_ZERO(&rfds);
    FD_SET(0, &rfds);
    int ret = select(1, &rfds, NULL, NULL, &tv);
    if (ret < 0) {
        perror("select");
        exit(1);
    }
    if (ret > 0) {
        scanf("%d", &age);
    } else {
        age = 100;
    }
    printf("suyelu is %d years old\n", age);
    return 0;
}
