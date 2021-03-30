/*************************************************************************
	> File Name: test.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: 2020年10月16日 星期五 18时27分01秒
 ************************************************************************/

#include <stdio.h>
#include <haizei/test.h>
#include <string.h>

int func_cnt = 0, total_count = 0 , success_count = 0;
Function func_arr[100];

int RUN_ALL_TESTS() {
    for (int i = 0; i < func_cnt; ++i) {
        printf("\033[32m[====RUN====]\033[0m \033[31m%s\033[0m\n", func_arr[i].str);
        func_arr[i].func();
        if (success_count == total_count)
            printf("\033[32m[\033[0m  \033[35m100.00%%\033[0m  \033[32m]\033[0m total : %d success : %d\n", total_count, success_count);
        else
            printf("\033[32m[\033[0m   \033[31m%.2lf%%\033[0m  \033[32m]\033[0m total : %d success : %d\n", success_count * 1.0 / total_count * 100, total_count, success_count);
        success_count = 0;
        total_count = 0;
    }
    return 0;
}

void add_function(TestFunc func, const char *str) {
    func_arr[func_cnt].func = func;
    func_arr[func_cnt].str = strdup(str); //将原字符串拷贝一份，然后将其赋值给一个变量
    func_cnt++;
    return;
}

void success_cnt(int a, int b, char *str) {
    if (!strcmp(str, "==")) success_count = a == b ? success_count + 1 : success_count;
    else if (!strcmp(str, "!=")) success_count = a != b ? success_count + 1 : success_count;
    else if (!strcmp(str, ">")) success_count = a > b ? success_count + 1 : success_count;
    else if (!strcmp(str, "<")) success_count = a < b ? success_count + 1 : success_count;
    else if (!strcmp(str, ">=")) success_count = a >= b ? success_count + 1 : success_count;
    else if (!strcmp(str, "<=")) success_count = a <= b ? success_count + 1 : success_count;
    ++total_count;
}
