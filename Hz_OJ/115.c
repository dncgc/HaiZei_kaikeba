/*************************************************************************
	> File Name: 115.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon 14 Sep 2020 11:40:16 AM CST
 ************************************************************************/

#include <stdio.h>

int award(int x, int y) {
    int tenx, onex, teny, oney;
    tenx = x / 10;
    onex = x % 10;
    teny = y / 10;
    oney = y % 10;
    if (x == y) return 100;
    else if(oney == tenx && teny == onex) return 20;
    else if(oney == tenx || oney == onex || teny == onex || teny == tenx)
        return 2;
    else return 0;
}

int main() {
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%d\n", award(x, y));
    return 0;
}
