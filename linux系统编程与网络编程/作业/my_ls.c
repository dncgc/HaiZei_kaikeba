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
#include <pwd.h>
#include <grp.h>
#include <time.h>

struct Detail {
    int links, size;
    char perm[16], user_name[32], group_name[32], mtime[32];
};

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
/*//bubble sort
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
//select sort
void sort_filename(char (*fname)[256], int n) {
    for (int i = 0; i < n - 1; i++) {
        int pos = i;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(fname[pos], fname[j]) < 0) continue;
            pos = j;
        }
        if (pos != i) swap(fname[pos], fname[i]);
    }
    return ;
}

int length(int n) {
    int ans = 0;
    while (n) {
        ans++;
        n /= 10;
    }
    return ans;
}

void printd(int n, int num) {
    int t = length(num);
    t = n - t;
    while (t--) printf(" ");
    printf("%d ", num);
    return ;
}

void prints(int n, const char *s) {
    int t = strlen(s);
    t = n - t;
    while (t--) printf(" ");
    printf("%s ", s);
    return ;
}

void get_detail(char (*fname)[256], struct Detail *detail, int n, int *mlinks, int *muname, int *mgname, int *msize) {
    for (int i = 0; i < n; i++) {
        struct stat sb;
        stat(fname[i], &sb);
        //mode
        for (int j = 0; j < 10; j++) detail[i].perm[j] = '-';
        detail[i].perm[10] = 0;
        switch (sb.st_mode & S_IFMT) {
            case S_IFBLK:  detail[i].perm[0] = 'b'; break;
            case S_IFCHR:  detail[i].perm[0] = 'c'; break;
            case S_IFDIR:  detail[i].perm[0] = 'd'; break;
            case S_IFIFO:  detail[i].perm[0] = 'p'; break;
            case S_IFLNK:  detail[i].perm[0] = 'l'; break;
            case S_IFREG:  detail[i].perm[0] = '-'; break;
            case S_IFSOCK: detail[i].perm[0] = 's'; break;
            default:       detail[i].perm[0] = 'u'; break;
        }
        if (sb.st_mode & S_IRUSR) detail[i].perm[1] = 'r';
        if (sb.st_mode & S_IWUSR) detail[i].perm[2] = 'w';
        if (sb.st_mode & S_IXUSR) detail[i].perm[3] = 'x';
        if (sb.st_mode & S_IRGRP) detail[i].perm[4] = 'r';
        if (sb.st_mode & S_IWGRP) detail[i].perm[5] = 'w';
        if (sb.st_mode & S_IXGRP) detail[i].perm[6] = 'x';
        if (sb.st_mode & S_IROTH) detail[i].perm[7] = 'r';
        if (sb.st_mode & S_IWOTH) detail[i].perm[8] = 'w';
        if (sb.st_mode & S_IXOTH) detail[i].perm[9] = 'x';
        //number of links
        detail[i].links = sb.st_nlink;
        int t = length(sb.st_nlink);
        (*mlinks) = (t > (*mlinks)) ? t : (*mlinks);
        //user Name
        struct passwd *pdu = getpwuid(sb.st_uid);
        strcpy(detail[i].user_name, pdu->pw_name);
        t = strlen(pdu->pw_name);
        (*muname) = (t > (*muname)) ? t : (*muname);
        //group Name
        struct group *grp = getgrgid(sb.st_gid);
        strcpy(detail[i].group_name, grp->gr_name);
        (*mgname) = (t > (*mgname)) ? t : (*mgname);
        //file size
        detail[i].size = sb.st_size;
        t = length(sb.st_size);
        (*msize) = (t > (*msize)) ? t : (*msize);
        //Time
        time_t curt = time(0);
        char *cur_t = ctime(&curt);
        int cur_year = atoi(cur_t + 20);
        char *t_temp = ctime(&sb.st_mtime);
        int t_year = atoi(t_temp + 20);
        if (t_year == cur_year) {
            strncpy(detail[i].mtime, t_temp + 4, 12);
            detail[i].mtime[12] = 0;
        }
        else {
            strncpy(detail[i].mtime, t_temp + 4, 7);
            strcat(detail[i].mtime, t_temp + 19);
        }
    }
}

void output_filename_info(char (*fname)[256], int n) {
    sort_filename(fname, n);
    struct Detail details[n];
    int mlinks = 0, muname = 0, mgname = 0, msize = 0;
    get_detail(fname, details, n, &mlinks, &muname, &mgname, &msize);
    for (int i = 0; i < n; i++) {
        if (fname[i][0] == '.') continue;
        printf("%s ", details[i].perm);
        printd(mlinks, details[i].links);
        prints(muname, details[i].user_name);
        prints(mgname, details[i].group_name);
        printd(msize, details[i].size);
        printf("%s ", details[i].mtime);
        printf("%s\n", fname[i]);
    }
    return ;
}

void output_all_filename_info(char (*fname)[256], int n) {
    sort_filename(fname, n);
    struct Detail details[n];
    int mlinks = 0, muname = 0, mgname = 0, msize = 0;
    get_detail(fname, details, n, &mlinks, &muname, &mgname, &msize);
    for (int i = 0; i < n; i++) {
        printf("%s ", details[i].perm);
        printd(mlinks, details[i].links);
        prints(muname, details[i].user_name);
        prints(mgname, details[i].group_name);
        printd(msize, details[i].size);
        printf("%s ", details[i].mtime);
        printf("%s\n", fname[i]);
    }
    return ;
}

void output_all_filename(char (*fname)[256], int n) {
    sort_filename(fname, n);
    for (int i = 0; i < n; i++) {
        printf("%s\n", fname[i]);
    }
}

void output_filename(char (*fname)[256], int n) {
    sort_filename(fname, n);
    for (int i = 0; i < n; i++) {
        if (fname[i][0] == '.') continue;
        printf("%s\n", fname[i]);
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

#define add_name() {\
    int t = 1, flag = 0;\
    while (argc > 1 && t < argc) {\
        if (argv[t][0] != '-') {\
            default_f = 0;\
            if (is_dir(argv[t]))\
                strcpy(dir_path[d_cnt++], argv[t]);\
            else if (is_file(argv[t]))\
                strcpy(file_path[f_cnt++], argv[t]);\
            else\
                printf("%s: cannot access \'%s\': No such file or directory\n", argv[0], argv[t]);\
            if (flag == 0) optind++;\
        }\
        else flag = 1;\
        t++;\
    }\
}

int main(int argc, char **argv) {
    int opt, l_flag = 0, a_flag = 0, default_f = 1;
    add_name();
    while ((opt = getopt(argc, argv, "al")) != -1) {
        switch (opt) {
            case 'a': a_flag = 1; break;
            case 'l': l_flag = 1; break;
            default: {
                fprintf(stderr, "Usage : %s [path] -a -l [path] !\n",argv[0]);
                exit(1);
            }
        }
    }

    if (f_cnt == 0 && d_cnt == 0 && default_f) strcpy(dir_path[d_cnt++], ".");
    if (f_cnt > 0) {
        if (l_flag) output_all_filename_info(file_path, f_cnt);
        else output_filename(file_path, f_cnt);
        if (d_cnt > 0) printf("\n");
    }
    int t = 0;
    while (t < d_cnt) {
        if (d_cnt > 1) printf("%s:\n", dir_path[t]);
        DIR *dir = opendir(dir_path[t]);
        dirent *dent;
        cnt = 0;
        while (dent = readdir(dir)) strcpy(file_name[cnt++], dent->d_name);
        if (a_flag && l_flag) output_all_filename_info(file_name, cnt);
        else if (a_flag) output_all_filename(file_name, cnt);
        else if (l_flag) output_filename_info(file_name, cnt);
        else output_filename(file_name, cnt);
        t++;
        if (d_cnt > 1 && t != d_cnt) printf("\n");
    }
    return 0;
}
