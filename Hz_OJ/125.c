/*************************************************************************
	> File Name: 125.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon 14 Sep 2020 05:35:29 PM CST
 ************************************************************************/
//输出百分号：%%
//c++编译时要在char前加const
#include <stdio.h>

void time(int h, int m, int s, int t) {
    int tt = t, hh, mm, ss;
    char *period;
    hh = tt / 3600 + h;
    mm = tt % 3600 / 60 + m;
    ss = tt % 3600 % 60 + s;
    if (ss  >= 60 ) {
        ss -= 60;
        mm++;
    }
    if (mm >= 60) {
        mm -= 60;
        hh++;
    }
    if (hh > 24)  hh -= 24;
    if (hh > 12) {
        period = ( hh == 24 ? "am" : "pm");
        hh -= 12;
    } else if(hh == 12)
        period = "pm";
    else
        period = "am";
    printf("%d:%d:%d%s\n", hh, mm, ss, period);

}

int main() {
    int h, m, s, t;
    scanf("%d%d%d%d", &h, &m, &s, &t);
    time(h, m, s, t);
    printf("%.2lf%%\n", t / 86400.0 * 100);
    return 0;
}
