/*************************************************************************
	> File Name: test.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: 2020年10月11日 星期日 19时37分28秒
 ************************************************************************/

#include <stdio.h> 
#include "header2.h" //自己写的头文件要用“”,从当前目录查找
#include "header1.h"
#include "header3.h"

int main() {
    funcA(5);
    funcC(5, 6);
    funcD(7, 8);
    return 0;
}
