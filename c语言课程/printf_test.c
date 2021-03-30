/*************************************************************************
	> File Name: printf_test.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: 2020年09月16日 星期三 20时21分28秒
 ************************************************************************/

#include <stdio.h>
#define swap(a, b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}

int main() {
    int n;
    scanf("%d", &n);//stdin 标准输入,从terminal输入
    printf("%d\n", n);//stdout terminal输出  stderr 标准错误输出 %4d %04d
    char str[1000] = {0}, buffer[1000] = {0}, *p = str, *q = buffer;
    sprintf(str, "%d.%d.%d.%d", 192.168.0.1);
    printf("str = %s\n", str);
    if (n & 1) {
        sprintf(q, "(%s)", p);
        swap(p, q);
    }
    if (n & 2) {
        sprintf(q, "[%s]", p);
        swap(p, q);
    }
    if (n & 4) {
        sprintf(q, "{%s}", p);
        swap(p, q);
    }
    printf("%s\n", str);
    FILE *fout = fopen("output", "w");
    fprintf(fout, "str = %s\n", p);
    fprintf(stderr, "str = %s\n", p);
    return 0;
}
