/*************************************************************************
	> File Name: 122.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon 14 Sep 2020 04:42:20 PM CST
 ************************************************************************/

#include <stdio.h>

void time(int t) {
    int tt = t, h = tt / 3600, m, s;
    if (h > 12) h -= 12;
    h < 10 ? printf("0%d:", h) : printf("%d:", h);
    tt %= 3600;
    m = tt / 60;
    m < 10 ? printf("0%d:", m) : printf("%d:", m);
    s = tt % 60;
    s < 10 ? printf("0%d ", s) : printf("%d ", s);
}

int main() {
    int t;
    char *period;
    scanf("%d", &t);
    if (t / 3600 < 12) period = "am";
    else if(t / 3600 > 12) period = "pm";
    else period = "midnoon";
    time(t);
    printf("%s\n", period);
    return 0;
}
