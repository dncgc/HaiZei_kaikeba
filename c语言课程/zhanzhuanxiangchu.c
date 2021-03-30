/*************************************************************************
	> File Name: zhanzhuanxiangchu.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: 2020年09月23日 星期三 18时49分33秒
 ************************************************************************/
//辗转相除
#include <stdio.h>

/*int gcd(int a, int b) {
    if (!b) {
        return a;
    }
    return gcd(b, a % b);
}*/

int gcd(int a, int b) {
    return (b ? gcd(b, a % b) : a);
}

int main() {
    int a, b;
    while(~scanf("%d%d", &a, &b)) {
        printf("%d\n", gcd(a, b));
    }
    return 0;
}
