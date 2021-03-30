/*************************************************************************
	> File Name: test.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: 2020年10月16日 星期五 18时27分01秒
 ************************************************************************/

#include <stdio.h>
#include <haizei/test.h>
#include <string.h>

int func_cnt = 0;
Function func_arr[100];

int RUN_ALL_TESTS() {
    for (int i = 0; i < func_cnt; ++i) {
        printf("RUN TESTS : %s\n", func_arr[i].str);
        func_arr[i].func();
        printf("RUN END\n");
    }
    return 0;
}

void add_function(TestFunc func, const char *str) {
    func_arr[func_cnt].func = func;
    func_arr[func_cnt].str = strdup(str); //将原字符串拷贝一份，然后将其赋值给一个变量
    func_cnt++;
    return;
}
