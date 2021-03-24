/*************************************************************************
	> File Name: my_fork.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 24 Mar 2021 06:53:55 PM CST
 ************************************************************************/

#include "head.h"

int main() {
    pid_t pid;
    for (int i = 1; i <= 10; i++) {
        if ((pid = fork()) < 0) {
            perror("fork");
            exit(1);
        }
        if (pid) {
            printf("fujincheng\n");
        } else {
            printf("这是%d号子进程\n", i);
        }
    }

    return 0;
}
