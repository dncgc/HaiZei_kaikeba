/*************************************************************************
	> File Name: 165.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 19 Sep 2020 02:44:57 PM CST
 ************************************************************************/
#include <stdio.h>
#include <math.h>
#include <inttypes.h>

/*int is_right(INT64_t a, INT64_t b, INT64_t c) {
    if(a * a + b * b == c * c)
        return 1;
    else return 0;
}*/

int binary_search(int64_t a, int64_t c) {
    int64_t mid; 
    int begin = a + 1, end = c - 1;
    while (begin <= end) {
        mid = (begin + end) >> 1;
        //__builtin_expect(!!(x), 0)
        if (a * a + mid * mid == c *c ) return 1;
        else if (a * a + mid * mid < c * c) begin = mid + 1;
        else end = mid - 1;
    }
    return 0;
}

int main() {
    int c; 
    int count = 0;
    scanf("%d", &c);
    for (int i = 1; i < c; i++) {
        count = (binary_search(i, c) ? ++count : count);
    }
    printf("%d\n", count);
    return 0;
}
