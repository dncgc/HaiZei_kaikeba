/*************************************************************************
	> File Name: while.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: 2020年09月20日 星期日 15时44分33秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    /*int n = 1;
    while (n <= 100) {
        printf("%d\n", n++);
    }
    for (int i = 1; i <= 100; i++) {
        printf("%d\n", i);
    }*/
    int a, b;
    srand(time(0)); //time(0)即为当前的时间,从1901.1.1到现在过了多少s,以这个时间生成随机种子
    printf("%ld\n", time(0));
    scanf("%d%d", &a, &b);
    if (a - b) { //a!=b
        printf("not equal!\n");
    } else {
        printf("equal!\n");
    }
    a = 0, b = 0;
    if (a++ && b++) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    printf("a = %d, b = %d\n", a, b);
    if (a++ || b++) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    printf("a = %d, b = %d\n", a, b);
    for (int i = 0; i < 10; i++) {
        i && printf(" ");
        printf("%d", i);
    }
    int cnt = 0;
    for (int i = 0; i < 5; i++) {
        int val = rand() % 100;//随机出一个整型值,但每次输出是一样的
        i && printf(" ");
        printf("%d", val);
        if (val % 2) cnt += 1;//val & 1 && cnt++;
        //cnt += (val & 1);
    }
    printf("\n");
    printf("add : %d\n", cnt)
    return 0;
}
