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
    int n = str2num(argv[1]), end = str2num(argv[3]);

    if ((fd = open(".data", O_CREAT | O_RDWR | O_TRUNC, 0666)) < 0) {
        perror("open");
        exit(1);
    }
    char buff[512] = {0};
    strcat(buff, "0 ");
    strcat(buff, argv[2]);
    write(fd, buff, strlen(buff) + 1);
    close(fd);
    
    for (int i = 0; i < n; i++) {
        if ((pid = fork()) < 0) {
            perror("fork");
            exit(1);
        }
        if (pid == 0) break;
    }
    if (pid == 0) {
        int f;
        ssize_t t;
        char *s_ans, *s_add;
        int ans, add;
        for(;;) {
            if ((fd = open(".data", O_RDONLY)) < 0) {
                perror("child_process open");
                exit(1);
            }
            if ((f = flock(fd, LOCK_EX)) == 0) {
                if ((t = read(fd, buff, 512)) < 0) {
                    perror("read");
                    exit(1);
                }
                s_ans = strtok(buff, " ");
                s_add = strtok(NULL, " ");
                add = str2num(s_add);
                if (add <= end) {
                    ans = str2num(s_ans);
                    ans += add;
                    add += 1;
                    sprintf(buff, "%d %d", ans, add);
                    close(fd);
                    fd = open(".data", O_TRUNC | O_RDWR);
                    write(fd, buff, strlen(buff) + 1);
                    flock(fd, LOCK_UN);
                    close(fd);
                } else {
                    flock(fd, LOCK_UN);
                    close(fd);
                    exit(0);
                }
            }
        }
    } else {
        for (int i = 0; i < n; i++) wait(NULL);
        if ((fd = open(".data", O_RDONLY)) < 0) {
            perror("parent_process open");
            exit(1);
        }
        if (read(fd, buff, 512) <= 0) {
            perror("read");
            exit(1);
        }
        printf("ans = %s\n", strtok(buff, " "));
        close(fd);
    }

    return 0;
}
