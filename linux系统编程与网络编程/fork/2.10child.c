/*************************************************************************
	> File Name: 2.10child.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 24 Mar 2021 07:04:57 PM CST
 ************************************************************************/

#include "head.h"

int main() {
    pid_t pid;
    int i = 1;
    for (; i <= 10; i++) {
        if ((pid = fork()) < 0) {
            perror("fork");
            exit(1);
        }
        if (pid == 0) {
            break;
        }
    }
    if (pid == 0) {
        printf("I'm the %dth Child Process!\n", i);
    } else {
        for (int i = 0; i < 10; i++) {
            wait(NULL);
        }
        printf("I'm Parent Process!\n");
    }

    return 0;
}

