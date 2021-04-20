/*************************************************************************
	> File Name: 1.popen.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 31 Mar 2021 06:47:06 PM CST
 ************************************************************************/

#include "head.h"

int main() {
    FILE *fp;
    char buff[512] = {0};
    if ((fp = my_popen("cat ./1.popen.c", "r")) == NULL) {
        perror("popen");
        exit(1);
    }
    while (fgets(buff, sizeof(buff), fp) != NULL) {
        printf("%s", buff);
        memset(buff, 0, sizeof(buff));
    }
    my_pclose(fp);
    return 0;
}
