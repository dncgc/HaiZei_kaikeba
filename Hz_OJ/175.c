/*************************************************************************
	> File Name: 175.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 19 Sep 2020 05:22:01 PM CST
 ************************************************************************/

#include <stdio.h>

int main() {
    int n, num, you = 0, liang = 0, zhong = 0, cha = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        if (num >= 90) you++;
        else if (num >= 80) liang++;
        else if (num >= 60) zhong++;
        else cha++;
    }
    printf("You %d\nLiang %d\nZhong %d\nCha %d\n", you, liang, zhong, cha);
    return 0;
}
