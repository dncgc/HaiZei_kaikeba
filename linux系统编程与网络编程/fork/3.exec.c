/*************************************************************************
	> File Name: 3.exec.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 24 Mar 2021 08:32:27 PM CST
 ************************************************************************/

#include "head.h"

int main() {
    pid_t pid;
    if ((pid = fork()) < 0) {
        perror("fork()");
        exit(1);
    }
    if (pid == 0) {
        execlp("ls", "ls", "/etc/hosts", NULL);
        printf("Haha\n"); //子进程已经替换为cat，不会再执行
        fflush(stdout);
    } else {
        int status;
        wait(&status);
        printf("status = %d\n", status);
    }

    return 0;
}
