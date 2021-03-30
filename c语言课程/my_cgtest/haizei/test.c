/*************************************************************************
	> File Name: haizei/test.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: 2020年10月23日 星期五 10时13分31秒
 ************************************************************************/

#include <stdio.h>
#include <haizei/test.h>
#include <string.h>
#include <stdlib.h>

TestInfo testinfo;
FunctionInfo funchead, *functail = &funchead;

int RUN_ALL_TESTS() {
    for (LinklistNode *p = funchead.pnext.next; p; p = p->next) {
        FunctionInfo *func = (FunctionInfo *)p;
        testinfo.total = 0, testinfo.success = 0;
        printf(GREEN("[====RUN====]") RED(" %s") "\n", func->funcname);
        func->func();
        printf(GREEN("[  "));
        if (testinfo.total == testinfo.success) printf(PURPLE("100.00%%"));
        else printf(RED("%6.2lf%%"), 100.0 * testinfo.success / (testinfo.total * 1.0));
        printf(GREEN("  ]") " total : %d    success : %d\n", testinfo.total, testinfo.success);
    }
    return 0;
}

void add_function(TestFunction func, const char *name) {
    FunctionInfo *temp = (FunctionInfo *)calloc(1, sizeof(FunctionInfo));
    temp->func = func;
    temp->funcname = strdup(name);
    functail->pnext.next = &(temp->pnext);
    functail = temp;
}
