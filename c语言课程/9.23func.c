/*************************************************************************
	> File Name: 9.23func.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: 2020年09月23日 星期三 20时34分32秒
 ************************************************************************/
//函数声明与函数定义
#include <stdio.h>

/*int funcB(int n) {
    if (n == 0) return 0;
    printf("funcB : %d\n", n);
    return 0;
}*/

int funcB(int n);

int funcA(int n) {
    if (n==0) return 0;
    printf("funcA : %d\n", n);
    funcB(n--);
    return 0;
}

int main() {
    funcA(5);
    return 0;
}
