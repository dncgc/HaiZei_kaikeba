/*************************************************************************
	> File Name: multi_process_add.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 26 Mar 2021 10:17:46 PM CST
 ************************************************************************/

#include "head.h"

int str2num(char *s) {
    int ans = 0;
    for (int i = 0; s[i]; i++) ans *= 10, ans += (s[i] - '0');
    return ans;
}

int main(int argc, char **argv) {
    int fd;
    pid_t pid;

    if (argc != 4) {
        fprintf(stderr, "Usage : %s process_numbers start end\n", argv[0]);
        exit(1);
    }
    int n = str2num(argv[1]);
    int start = str2num(argv[2]), end = str2num(argv[3]);

    if ((fd = open(".data", O_CREAT | O_RDWR, 0666)) < 0) {
        perror("open");
        exit(1);
    }
    char buff[512] = {0};
    strcat(buff, "0 ");
    strcat(buff, argv[2]);
    write(fd, buff, strlen(buff) + 1);
    
    for (int i = 0; i < n; i++) {
        if ((pid = fork()) < 0) {
            perror("fork");
            exit(1);
        }
        if (pid == 0) break;
    }
    if (pid == 0) {
        int f;
        for(;;) {
            if ((f = flock(fd, LOCK_EX)) == 0) {

            }
        }
    } else {
        for (int i = 0; i < n; i++) wait(NULL);
        close(fd);
    }

    return 0;
}
