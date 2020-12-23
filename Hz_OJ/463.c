/*************************************************************************
	> File Name: 463.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue Oct  6 17:51:02 2020
 ************************************************************************/

#include <stdio.h>

struct Window {
    int l, r, u, b;
};

int overlap_area(struct Window w1, struct Window w2) {
    int len = 0, weight = 0;
    if ((w1.l - w2.l) * (w1.r - w2.l) < 0 && (w1.l - w2.r) * (w1.r - w2.r) < 0)
        len = w2.r - w2.l;
    else if ((w1.l - w2.l) * (w1.r - w2.l) < 0) len = w1.r - w2.l;
    else if ((w1.l - w2.r) * (w1.r - w2.r) < 0) len = w2.r - w1.l;
    if ((w1.u - w2.u) * (w1.b - w2.u) < 0 && (w1.u - w2.b) * (w1.b - w2.b) < 0)
        weight = w2.b - w2.u;
    else if ((w1.u - w2.u) * (w1.b - w2.u) < 0) weight = w1.b - w2.u;
    else if ((w1.u - w2.b) * (w1.b - w2.b) < 0) weight = w2.b - w1.u;
    return len * weight;
}

int main() {
    struct Window w1, w2;
    scanf("%d%d%d%d", &w1.l, &w1.r, &w1.u, &w1.b);
    scanf("%d%d%d%d", &w2.l, &w2.r, &w2.u, &w2.b);
    printf("%d\n", overlap_area(w1, w2));
    return 0;
}
