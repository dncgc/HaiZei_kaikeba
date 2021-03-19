/*************************************************************************
	> File Name: 4.dir.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 19 Mar 2021 07:39:38 PM CST
 ************************************************************************/

#include "head.h"

int main(int argc, char **argv) {
    char dir_name[256] = {0};
    DIR *dir = NULL;
    if (argc == 1) {
        strcpy(dir_name, ".");
    } else {
        strcpy(dir_name, argv[1]);
    }

    if ((dir = opendir(dir_name)) == NULL) {
        perror(dir_name);
        exit(1);
    }

    while (1) {
        struct dirent *dir_ptr;
        if ((dir_ptr = readdir(dir)) == NULL) {
            break;
        }
        printf("%s\n", dir_ptr->d_name);
    }
    closedir(dir);
    return 0;
}
