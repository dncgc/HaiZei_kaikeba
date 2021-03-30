/*************************************************************************
	> File Name: max_int.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: 2020年09月23日 星期三 20时19分53秒
 ************************************************************************/
//变参函数，至此函数所有内容已讲完
#include <stdio.h>
#include <stdarg.h>

int max_int(int n, ...) {
    if (n < 0) return 0;
    int ans = 0;
    va_list arg;
    va_start(arg, n); //将n后面的内容给arg
    while (n--) {
        int temp = va_arg(arg, int);//可知va_arg不是函数
        if (temp > ans) ans = temp;
    }
    va_end(arg);
    return ans;
}

int main() {
    printf("%d\n", max_int(3, 1, 2, 5));
    printf("%d\n", max_int(2, 1, 2, 5, 17));
    printf("%d\n", max_int(3, 3, 6, 18));
    return 0;
}
