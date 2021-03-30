/*************************************************************************
	> File Name: 10.9_string_10to16.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: 2020年10月09日 星期五 20时03分55秒
 ************************************************************************/
//使用字符串相关操作方法，计算一个整型16进制表示的位数。
#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char str[12];
    while (~scanf("%d", &n)); {
        sprintf(str,"%X", n);
        printf("%s has %lu digits!\n", str, strlen(str));
    }
    return 0;
}
