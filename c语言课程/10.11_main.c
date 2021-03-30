/*************************************************************************
	> File Name: 10.11_main.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: 2020年10月11日 星期日 18时39分12秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ppchar char *
typedef char * pchar;

void output(int argc, char *argv[], char **env) {
    printf("argc = %d\n", argc);
    for (int i = 0; i < argc; ++i) {
        printf("%s\n", argv[i]);
    }
    for (int i = 0; env[i]; ++i) {
        if (!strncmp(env[i], "USER=", 5)) {
            if (!strcmp(env[i] + 5, "cgc")) {
                printf("welcome cui\n");
            } else {
                printf("you are not the user! please gun!\n");
                exit(0);
            }
        }
    }
    return ;
}

int main(int argc, char *argv[], char **env) {
    pchar p1, p2;
    ppchar p3, p4;//简单的代码替换会出bug
    printf("p1 = %lu, p2 = %lu\n", sizeof(p1), sizeof(p2));
    printf("p3 = %lu, p4 = %lu\n", sizeof(p3), sizeof(p4));
    output(argc, argv, env);
    return 0;
}
