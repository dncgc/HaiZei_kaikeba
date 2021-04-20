/*************************************************************************
	> File Name: my_popen.h
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 31 Mar 2021 07:24:09 PM CST
 ************************************************************************/

#ifndef _MY_POPEN_H
#define _MY_POPEN_H
FILE *my_popen(const char *cmd, const char *type);
int my_pclose(FILE *fp);
#endif
