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
#include <sys/ioctl.h>
#include <termios.h>

#define GREEN(a)      printf("\033[1;32m%s\033[0m", a)
#define BLUE(a)       printf("\033[1;34m%s\033[0m", a)
#define LIGHT_BLUE(a) printf("\033[1;36m%s\033[0m", a)
#define YELLOW(a)     printf("\033[1;33m%s\033[0m", a)

typedef int (*func)(const char *, const char *);

struct Detail {
    int links, size;
    char perm[16], user_name[32], group_name[32], mtime[32];
};

typedef struct dirent dirent;
char file_name[512][256];
char file_path[128][256], dir_path[128][256];
char cur_dirpath[256];
int cnt, f_cnt, d_cnt;

void swap(char *, char *);
int my_strlen(const char *);
int char_to_int(char);
int my_strcmp(const char *, const char *);
void sort_filename(char (*)[256], int start, int end, func);
int length(int);
int is_file(const char *);
int is_dir(const char *);
void get_detail(char (*)[256], struct Detail *, int n, int *max_links, int *max_uname, int *max_gname, int *max_size);
void get_info(char (*)[256], char (*)[16], int n, int *max_len);
void output_filename_info(char (*)[256], int n, int flag);
void get_suit_col(char (*)[256], int start, int n, int *col, int max_len);
void output_filename(char (*fname)[256], int n, int flag);

#define ADD_NAME() {\
    int t = 1, flag = 0;\
    while (argc > 1 && t < argc) {\
        if (argv[t][0] != '-') {\
            default_f = 0;\
            if (is_dir(argv[t]))\
                strcpy(dir_path[d_cnt++], argv[t]);\
            else if (is_file(argv[t]))\
                pd_flag = 1, strcpy(file_path[f_cnt++], argv[t]);\
            else\
                pd_flag = 1, printf("%s: cannot access \'%s\': No such file or directory\n", argv[0], argv[t]);\
            if (flag == 0) optind++;\
        }\
        else flag = 1;\
        t++;\
    }\
}

int main(int argc, char **argv) {
    int opt, l_flag = 0, a_flag = 0, default_f = 1, pd_flag = 0;
    ADD_NAME();
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
        if (l_flag) output_filename_info(file_path, f_cnt, 1);
        else output_filename(file_path, f_cnt, 1);
        if (d_cnt > 0) printf("\n");
    }
    if (d_cnt > 1) sort_filename(dir_path, 0, d_cnt, my_strcmp);
    int t = 0;
    while (t < d_cnt) {
        if (d_cnt > 1 || pd_flag) printf("%s:\n", dir_path[t]);
        DIR *dir = opendir(dir_path[t]);
        dirent *dent;
        cnt = 0;
        strcpy(cur_dirpath, dir_path[t]);
        while (dent = readdir(dir))
            strcpy(file_name[cnt++], dent->d_name);
        if (l_flag) output_filename_info(file_name, cnt, a_flag);
        else output_filename(file_name, cnt, a_flag);
        t++;
        if (d_cnt > 1 && t != d_cnt) printf("\n");
    }
    return 0;
}

void swap(char *a, char *b) {
    char *c = (char *)malloc(sizeof(char) * 256);
    strcpy(c, a);
    strcpy(a, b);
    strcpy(b, c);
    free(c);
    return ;
}

int my_strlen(const char *str) {
    int len = 0, cnt = 0;
    while (str[len]) {
        cnt += (str[len] < 0);
        len++;
    }
    return len - cnt / 3;
}

int char_to_int(char ch) {
    if (ch >= 'A' && ch <= 'Z') return ch - 'A' + 'a';
    if (ch < 0) return 512 + ch; //汉字
    return ch;
}

int my_strcmp(const char *s1, const char *s2) {
    int i = 0, j = 0;
    if (s1[0] == '.' && s1[1] != 0 && s1[1] != '.') i = 1;
    if (s2[0] == '.' && s2[1] != 0 && s2[1] != '.') j = 1;
    for ( i, j; s1[i] && s2[j]; i++, j++) {
        int t1 = char_to_int(s1[i]), t2 = char_to_int(s2[j]);
        if (t1 == t2) continue;
        if (t1 < t2) return -1;
        if (t1 > t2) return 1;
    }
    if (s1[i]) return 1;
    if (s2[j]) return -1;
    return 0;
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
void sort_filename(char (*fname)[256], int s, int n, func f) {
    for (int i = s; i < n - 1; i++) {
        int pos = i;
        for (int j = i + 1; j < n; j++) {
            if (f(fname[pos], fname[j]) < 0) continue;
            pos = j;
        }
        if (pos != i) swap(fname[pos], fname[i]);
    }
    return ;
}

int length(int n) {
    int ans = 0;
    do {
        ans++;
        n /= 10;
    } while (n);
    return ans;
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

#define GET_MODE(a) {\
    for (int j = 0; j < 10; j++) a[j] = '-';\
    a[10] = 0;\
    switch (sb.st_mode & S_IFMT) {\
        case S_IFBLK:  a[0] = 'b'; break;\
        case S_IFCHR:  a[0] = 'c'; break;\
        case S_IFDIR:  a[0] = 'd'; break;\
        case S_IFIFO:  a[0] = 'p'; break;\
        case S_IFLNK:  a[0] = 'l'; break;\
        case S_IFREG:  a[0] = '-'; break;\
        case S_IFSOCK: a[0] = 's'; break;\
        default:       a[0] = 'u'; break;\
    }\
    if (sb.st_mode & S_IRUSR) a[1] = 'r';\
    if (sb.st_mode & S_IWUSR) a[2] = 'w';\
    if (sb.st_mode & S_IXUSR) a[3] = 'x';\
    if (sb.st_mode & S_IRGRP) a[4] = 'r';\
    if (sb.st_mode & S_IWGRP) a[5] = 'w';\
    if (sb.st_mode & S_IXGRP) a[6] = 'x';\
    if (sb.st_mode & S_IROTH) a[7] = 'r';\
    if (sb.st_mode & S_IWOTH) a[8] = 'w';\
    if (sb.st_mode & S_IXOTH) a[9] = 'x';\
}

void get_detail(char (*fname)[256], struct Detail *detail, int n, int *mlinks, int *muname, int *mgname, int *msize) {
    if (cur_dirpath[0] && cur_dirpath[my_strlen(cur_dirpath) - 1] != '/')
        strcat(cur_dirpath, "/");
    for (int i = 0; i < n; i++) {
        struct stat sb;
        char filename[256];
        strcpy(filename, cur_dirpath);
        strcat(filename, fname[i]);
        lstat(filename, &sb);
        //mode
        GET_MODE(detail[i].perm);
        //number of links
        detail[i].links = sb.st_nlink;
        int t = length(sb.st_nlink);
        (*mlinks) = (t > (*mlinks)) ? t : (*mlinks);
        //user Name
        struct passwd *pdu = getpwuid(sb.st_uid);
        strcpy(detail[i].user_name, pdu->pw_name);
        t = my_strlen(pdu->pw_name);
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
        //int cur_year = atoi(cur_t + 20);
        char *t_temp = ctime(&sb.st_mtime);
        //int t_year = atoi(t_temp + 20);
        if (curt - sb.st_mtime < 15768000) {
            strncpy(detail[i].mtime, t_temp + 4, 12);
            detail[i].mtime[12] = 0;
        }
        else {
            strncpy(detail[i].mtime, t_temp + 4, 7);
            strcat(detail[i].mtime, t_temp + 19);
            detail[i].mtime[my_strlen(detail[i].mtime) - 1] = 0;
        }
    }
    return ;
}

void get_info(char (*fname)[256], char (*perm)[16], int n, int *m_len) {
    if (cur_dirpath[0] && cur_dirpath[my_strlen(cur_dirpath) - 1] != '/')
        strcat(cur_dirpath, "/");
    for (int i = 0; i < n; i++) {
        int t = my_strlen(fname[i]);
        if (t > (*m_len)) (*m_len) = t;
        struct stat sb;
        char filename[256];
        strcpy(filename, cur_dirpath);
        strcat(filename, fname[i]);
        lstat(filename, &sb);
        //mode
        GET_MODE(perm[i]);
    }
    return ;
}

void output_filename_info(char (*fname)[256], int n, int flag) {
    if (flag) sort_filename(fname, 0, n, my_strcmp);
    else sort_filename(fname, 0, n, strcmp);
    int count = 0;
    if (!flag) {
        while (fname[count][0] == '.') count++;
        sort_filename(fname, count, n, my_strcmp);
    }
    struct Detail details[n];
    int mlinks = 0, muname = 0, mgname = 0, msize = 0;
    get_detail(fname, details, n, &mlinks, &muname, &mgname, &msize);
    for (int i = count; i < n; i++) {
        printf("%s ", details[i].perm);
        printf("%*d %.*s %.*s %*d ", mlinks, details[i].links, muname,
               details[i].user_name, mgname, details[i].group_name, 
               msize, details[i].size);
        printf("%s ", details[i].mtime);
        if (details[i].perm[0] == 'd')
            BLUE(fname[i]);
        else if (details[i].perm[0] == 'c' || details[i].perm[0] == 'b')
            YELLOW(fname[i]);
        else if (details[i].perm[0] == 'l') {
            char buf[256];
            ssize_t n_bytes;
            n_bytes = readlink(fname[i], buf, 256);
            LIGHT_BLUE(fname[i]);
            buf[n_bytes] = 0;
            printf(" -> ");
            if (is_dir(buf)) BLUE(buf);
            else printf("%s", buf);
        }
        else if (details[i].perm[3] == 'x' || details[i].perm[6] == 'x'
                 || details[i].perm[9] == 'x')
            GREEN(fname[i]);
        else printf("%s", fname[i]);
        printf("\n");
    }
    return ;
}

#define PRINT_NAME() {\
    if (perm[ind][0] == 'd') {\
        BLUE(fname[ind]);\
    }\
    else if (perm[ind][0] == 'c' || perm[ind][0] == 'b') {\
        YELLOW(fname[ind]);\
    }\
    else if (perm[ind][0] == 'l') {\
        LIGHT_BLUE(fname[ind]);\
    }\
    else if (perm[ind][3] == 'x' || perm[ind][6] == 'x' || perm[ind][9] == 'x') {\
        GREEN(fname[ind]);\
    }\
    else printf("%s", fname[ind]);\
    if (j == col - 1 || index[i][j + 1] == -1) continue;\
    while (t--) printf(" ");\
}

void get_suit_col(char (*fname)[256], int s, int n, int *col, int max_len) {
    int c = (*col) + 1, flag = 1;
    n = n - s;
    while (flag) {
        if (n / c == 0) break;
        int r = (n % c) ? (n / c + 1) : (n / c);
        int index[r][c], max_len_col[c];
        memset(index, 0, sizeof(index));
        memset(max_len_col, 0, sizeof(max_len_col));
        int temp = n % c;
        while (temp && temp < c) index[r - 1][temp++] = -1;
        for (int i = 0, count = s; i < c; i++) {
            for (int j = 0; j < r; j ++) {
                if (index[j][i] == -1) continue;
                index[j][i] = count;
                int l = my_strlen(fname[count]);
                if (l > max_len_col[i]) max_len_col[i] = l;
                count++;
            }
        }
        for (int i = 0; i < r; i++) {
            int len = 0;
            for (int j = 0; j < c; j++) {
                int ind = index[i][j];
                if (ind == -1) continue;
                len += max_len_col[j];
                if (j < c - 1 && index[i][j + 1] != -1) len += 2;
            }
            if (len > max_len) {
                flag = 0;
                break;
            }
        }
        if (flag == 0) break;
        c++;
    }
    (*col) = c - 1;
    return ;
}

#define PRINT_IN_COL() {\
    int row = (n % col) ? (n / col + 1) : (n / col);\
    int index[row][col], max_len_col[col];\
    memset(index, 0, sizeof(index));\
    memset(max_len_col, 0, sizeof(max_len_col));\
    int temp = n % col;\
    while (temp && temp < col) index[row - 1][temp++] = -1;\
    for (int i = 0; i < col; i++) {\
        for (int j = 0; j < row; j++) {\
            if (index[j][i] == -1) continue;\
            index[j][i] = count;\
            int l = my_strlen(fname[count]);\
            if(l > max_len_col[i]) max_len_col[i] = l;\
            count++;\
        }\
    }\
    for (int i = 0; i < row; i++) {\
        for (int j = 0; j < col; j++) {\
            int ind = index[i][j];\
            if (ind == -1) continue;\
            int t = max_len_col[j] + 2 - my_strlen(fname[ind]);\
            PRINT_NAME();\
        }\
        i == row - 1 || printf("\n");\
    }\
    printf("\n");\
}

void output_filename(char (*fname)[256], int n, int flag) {
    if (flag) sort_filename(fname, 0, n, my_strcmp);
    else sort_filename(fname, 0, n, strcmp);
    int count = 0;
    if (!flag) {
        while (fname[count][0] == '.') count++;
        sort_filename(fname, count, n, my_strcmp);
    }
    char perm[n][16];
    int max_len = 0;
    get_info(fname, perm, n, &max_len);
    //get terminal size
    struct winsize size;
    ioctl(STDIN_FILENO, TIOCGWINSZ, &size);
    int col = size.ws_col / (max_len + 2);
    get_suit_col(fname, count, n, &col, size.ws_col);
    n = n - count;

    PRINT_IN_COL();
    return ;
}
