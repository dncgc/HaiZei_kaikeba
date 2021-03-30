/*************************************************************************
	> File Name: 10.11_pointer.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: 2020年10月11日 星期日 16时34分18秒
 ************************************************************************/
//类型作为参数进行传递用宏
#include <stdio.h>
/*#define offset(T, a) ({\
    T temp;\
    (char *)&temp.a - (char *)&temp;\
})**/
#define offset(T, a) (long)(&(((T*)(NULL))->a))

struct Data {
    int a;
    double b;
    char c;
};

int main() {
    int num = 0x616263;
    printf("%s\n", (char *)(&num));
    int num1 = 0x616263;
    int num2 = 0x61626364;
    //printf("%s\n", (char *)(&num2));
    printf("%s\n", (char *)(&num2 + 1));
    printf("%ld\n", offset(struct Data, a));
    printf("%ld\n", offset(struct Data, b));
    printf("%ld\n", offset(struct Data, c));
    return 0;
}
