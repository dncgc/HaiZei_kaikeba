/*************************************************************************
	> File Name: my_ls.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 19 Mar 2021 03:45:15 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <fcntl.h>

typedef struct dirent dirent;
char file_name[256][256], cnt;
char file_path[128][256], f_cnt, dir_path[128][256], d_cnt;

void swap(char *a, char *b) {
    char *c = (char *)malloc(sizeof(char) * 256);
    strcpy(c, a);
    strcpy(a, b);
    strcpy(b, c);
    free(c);
    return ;
}
/*//bubble
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
*/
void sort_filename() {
    for (int i = 0; i < cnt - 1; i++) {
        int pos = i;
        for (int j = i + 1; j < cnt; j++) {
            if (strcmp(file_name[pos], file_name[j]) < 0) continue;
            pos = j;
        }
        if (pos != i) swap(file_name[pos], file_name[i]);
    }
    return ;
}

void output_filename_info() {
    sort_filename();
    for (int i = 0; i < cnt; i++) {
        printf("%s\n", file_name[i]);
    }
}

void output_all_filename_info() {
    sort_filename();
    for (int i = 0; i < cnt; i++) {
        printf("%s\n", file_name[i]);
    }
}

void output_all_filename() {
    sort_filename();
    for (int i = 0; i < cnt; i++) {
        printf("%s\n", file_name[i]);
    }
}

void output_filename() {
    sort_filename();
    for (int i = 0; i < cnt; i++) {
        if (file_name[i][0] == '.') continue;
        printf("%s\n", file_name[i]);
    }
}

int is_file(const char *path) {
    int flag = 0;
    int fd = open(path, O_RDONLY);
    if (fd >= 0) { close(fd); flag = 1; }
    return flag;
}

int is_dir(const char *path) {
    int flag = 0;
    DIR *dir = opendir(path);
    if (dir) { flag = 1; closedir(dir); }
    return flag;
}

int main(int argc, char **argv) {
    int opt, l_flag = 0, a_flag = 0;
    while (argc > 1 && argv[optind][0] != '-') {
        if (is_file(argv[optind]))
            strcpy(file_path[f_cnt++], argv[optind++]);
        else if (is_dir(argv[optind]))
            strcpy(dir_path[d_cnt++], argv[optind++]);
        else
            printf("%s: cannot access \'%s\': No such file or directory\n",
                  argv[0], argv[optind++]);
    }
    while ((opt = getopt(argc, argv, "al")) != -1) {
        switch (opt) {
            case 'a': a_flag = 1; break;
            case 'l': l_flag = 1; break;
            default:
                if ()
                fprintf(stderr, "Usage : %s [path] -a -l [path] !\n", argv[0]);
                exit(1);
        }
    }

    DIR *dir = opendir(path);
    if (dir) {
        dirent *dent;
        while (dent = readdir(dir)) strcpy(file_name[cnt++], dent->d_name);
        if (a_flag && l_flag) output_all_filename_info();
        else if (a_flag) output_all_filename();
        else if (l_flag) output_filename_info();
        else output_filename();
    } else {
        fprintf(stderr, "It's not a directory or the directory is not exist!\n");
        exit(1);
    }
    return 0;
}
