/*************************************************************************
	> File Name: my_ls.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 19 Mar 2021 03:45:15 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

typedef struct dirent dirent;
char file_name[100][100], cnt;

void swap(char *a, char *b) {
    char *c = (char *)malloc(sizeof(char) * 100);
    strcpy(c, a);
    strcpy(a, b);
    strcpy(b, c);
    free(c);
    return ;
}

void sort_filename() {
    for (int i = 0; i < cnt - 1; i++) {
        int flag = 0;
        for (int j = 0; j < cnt - 1 - i; j++) {
            if (strcmp(file_name[j], file_name[j + 1]) < 0) continue;
            swap(file_name[j], file_name[j + 1]);
            flag = 1;
        }
        if (!flag) break;
    }
    return ;
}

void output_filename() {
    sort_filename();
    for (int i = 0; i < cnt; i++) {
        printf("%s\n", file_name[i]);
    }
}

int main(int argc, char **argv) {
    DIR *dir = opendir(".");
    int opt, flag = 0;
    while ((opt = getopt(argc, argv, "a::l::")) != -1) {
        switch (opt) {
            case 'a': flag |= 1; break;
            case 'l': flag |= 2; break;
            default:
                fprintf(stderr, "Usage : %s -a -l !\n", argv[0]);
                exit(1);
        }
    }
    if (dir) {
        dirent *dent;
        while (dent = readdir(dir)) strcpy(file_name[cnt++], dent->d_name);
        output_filename();
    } else {
        fprintf(stderr, "The directory cannot be opened!\n");
        exit(1);
    }
    printf("flag = %d\n", flag);

    return 0;
}
