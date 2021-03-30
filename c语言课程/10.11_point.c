/*************************************************************************
	> File Name: 10.11_point.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: 2020年10月11日 星期日 15时25分39秒
 ************************************************************************/

#include <stdio.h>
#define P(a) {\
    printf("%s = %d\n", #a, a);\
}

struct Data {
    int x, y;
};

int main() {
    struct Data a[2], *p = a;
    a[0].x = 1, a[0].y = 1;
    a[1].x = 2, a[1].y = 2;
    P(a[1].x);
    P((a + 1) -> x);
    P((p + 1) -> x);
    P(p[1].x);
    P((*(p + 1)).x);
    P((*(a + 1)).x);
    P((&a[1])->x);
    P((&p[1])->x);
    P((&a[0] + 1)->x);
    P((*(&a[0] + 1)).x);
    P(*((int *)p + 2));
    return 0;
}
