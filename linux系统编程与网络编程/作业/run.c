/*************************************************************************
	> File Name: run.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sun 25 Apr 2021 05:02:49 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void get_name(char *per, char *post, const char *name) {
    int pos = 0;
    for (int i = 0; name[i]; i++) {
        if (name[i] == '.') pos = i;
    }
    strncpy(per, name, pos);
    per[pos] = 0;
    strcpy(post, name + pos + 1);
    return ;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage : %s file_name !\n", argv[0]);
        exit(1);
    }
    int fd;
    if ((fd = open(argv[1], O_RDONLY)) < 0) {
        pid_t pid;
        if ((pid = fork()) < 0) {
            perror("fork()");
            exit(1);
        }
        if (pid == 0) {
            execlp("vim", "vim", argv[1], NULL);
        } else {
            int status;
            wait(&status);
            if (status != 0) {
                perror("vim");
                exit(1);
            }
        }
    }
    close(fd);
    pid_t pid;
    char per_name[128], post_name[16];
    get_name(per_name, post_name, argv[1]);
    if ((pid = fork()) < 0) {
        perror("fork");
        exit(1);
    }
    if (pid == 0) {
        if (strcmp(post_name, "c") == 0)
            execlp("gcc", "gcc", argv[1], "-o", per_name, NULL);
        else if (strcmp(post_name, "cpp") == 0)
            execlp("g++", "g++", argv[1], "-o", per_name, NULL);
        else {
            fprintf(stderr, "The file type doesn't support to run!\n");
            exit(1);
        }
    } else {
        int status;
        wait(&status);
        if (status != 0) {
            perror("gcc");
            exit(1);
        }
    }

    char command[256];
    strcpy(command, "./");
    strcpy(command, per_name);
    if ((pid = fork()) < 0) {
        perror("fork3");
        exit(1);
    }
    if (pid == 0) {
        execl(command, per_name, NULL);
    } else {
        int status;
        wait(&status);
        if (status != 0) {
            perror(command);
            exit(1);
        }
    }
    return 0;
}
