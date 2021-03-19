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

void sort_filename() {
    
}

void output_filename() {
    sort_filename();
    for (int i = 0; i < cnt; i++) {
        printf("%s\n", file_name[i]);
    }
}

int main(int argc, char **argv) {
    int opt;
    while ((opt = getopt(argc, argv, "ab")) != -1) {
        switch (opt) {
            case 'a': break;
            case 'l': break;
            default:
                fprintf(stderr, "Usage : %s -a -l !\n", argv[0]);
                exit(1);
        }
    }
    DIR *dir = opendir("./");
    if (dir) {
        dirent *dent;
        while (dent = readdir(dir)) strcpy(file_name[cnt++], dent->d_name);
        output_filename();
    } else {
        fprintf(stderr, "The directory cannot be opened!\n");
        exit(1);
    }

    return 0;
}
