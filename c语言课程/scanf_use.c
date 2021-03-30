/*************************************************************************
	> File Name: scanf_use.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: 2020年09月16日 星期三 19时25分55秒
 ************************************************************************/
//scanf读入可能包含空格的情况
//[]正则表达式
//输出输入字符串中字符数量
#include <stdio.h>

int main() {
    char str[100] = {0};
    //int ret; 调试用 令ret = scanf的返回值
    while (scanf("%[^\n]s", str) != EOF) {
        getchar(); //强制吞掉一个字符，否则会卡在\n进入死循环
        printf(" has %d chars!\n", printf("%s", str));
    } //[]只读取满足[]中条件的字符  除了\n都可读入 ^为异或
   
    return 0;
}
