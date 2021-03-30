/*************************************************************************
	> File Name: test.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: 2020年10月16日 星期五 18时27分01秒
 ************************************************************************/

#include <stdio.h>
#include <haizei/test.h>
#include <string.h>
#include <math.h>

int func_cnt = 0;
Function func_arr[100];
struct FunctionInfo haizei_test_info;

int RUN_ALL_TESTS(){
    for (int i = 0; i < func_cnt; ++i) {
        printf(GREEN("[====RUN====]") RED_HL(" %s") "\n", func_arr[i].str);
        haizei_test_info.total = 0, haizei_test_info.success = 0;
        func_arr[i].func();
        double rate = 100.0 * haizei_test_info.success / haizei_test_info.total;
        printf(GREEN("[  "));
        if (fabs(rate - 100.0) < 1e-6) {
            printf(BULE_HL("%6.2lf%%"), rate);
        } else {
            printf(RED_HL("%6.2lf%%"), rate);
        }
        printf(GREEN("  ]") " total : %d    success : %d\n", 
            haizei_test_info.total, 
            haizei_test_info.success);
    }
    return 0;
}

void add_function(TestFunc func,const char *str) { //const char *str
    func_arr[func_cnt].func = func;
    func_arr[func_cnt].str = strdup(str); //将原字符串拷贝一份，然后将其赋值给一个变量
    func_cnt++;
    return;
}

/*void count(const char *str) {
    if (!strncmp(str, "total", 5)) ++total;
    else ++faile;
}*/
