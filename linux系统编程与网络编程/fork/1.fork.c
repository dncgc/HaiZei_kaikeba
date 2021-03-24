/*************************************************************************
	> File Name: 1.fork.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 24 Mar 2021 06:39:39 PM CST
 ************************************************************************/

#include "head.h"

int main() {
    pid_t pid;
    if ((pid = fork()) < 0) {
        perror("fork()");
        exit(1);
    }
    if (pid) {
        printf("In Parent Process! <%d>--><%d>--><%d>\n", getppid(), getpid(), pid);
    } else {
        printf("In Child Process! <%d>--><%d>\n", getppid(), getpid());
    }
    return 0;
}
