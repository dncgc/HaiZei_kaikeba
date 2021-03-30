/*************************************************************************
	> File Name: if_else.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: 2020年09月20日 星期日 14时19分40秒
 ************************************************************************/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
   /* if (!n) printf("FOOLISH\n");
    else if (n < 60) printf("FALL\n");
    else if (n < 75) printf("MEDIUM\n");
    else if (n <= 100) printf("GOOD\n");*/
    switch (n) {
        case 1:
            printf("one\n");
            //break;
        case 2:
            printf("two\n");
            //break;
        case 3:
            printf("three\n");
            break;
        default:
            printf("error\n");
            break;
    }
    return 0;
}
