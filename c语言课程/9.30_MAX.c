/*************************************************************************
	> File Name: 9.30_MAX.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: 2020年09月30日 星期三 20时38分49秒
 ************************************************************************/

#include <stdio.h>
#define MAX(a, b) ({\
    __typeof(a) _a = a;\
    __typeof(b) _b = b;\
    _a > _b ? _a : _b;\
})

//#作用：将a的内容字符串化
#define P(a) {\
    printf("%s = %d\n", #a, a);\
}

int main() {
    int a = 7;
    P(MAX(2, 3));
    P(5 + MAX(2, 3));
    P(MAX(2, MAX(3, 4)));
    P(MAX(2, 3 > 4 ? 3 : 4));
    P(MAX(a++, 6));
    P(a);
    return 0;
}
