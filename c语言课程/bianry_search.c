/*************************************************************************
	> File Name: erfencahzhao.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: 2020年09月20日 星期日 20时42分00秒
 ************************************************************************/

#include <stdio.h>
#include <inttypes.h>

int64_t Triangle(int64_t n) {
    return n * (n + 1) >> 1;
}

int64_t Pentagonal(int64_t n) {
    return n * (3 * n - 1) >> 1;
}

int64_t Hexagonal(int64_t n) {
    return n * ((n << 1) - 1);
}

int64_t binary_search(int64_t (*func)(int64_t), int64_t x) {
    int64_t head = 1, tail = x, mid;
    while (head <= tail) {
        mid = (head + tail) >> 1;
        if (func(mid) == x) return mid;
        else if (func(mid) < x) head = mid + 1;
        else tail = mid - 1;
    }
    return -1;
}
int main() {
    int n = 1;//143
    while (1) {
        n++;
        int64_t val = Hexagonal(n);
        //if (binary_search(Triangle, val) == -1) continue;
        if (binary_search(Pentagonal, val) == -1) continue;
        break;
    }
    printf("%" PRId64"\n", Hexagonal(n));
    return 0;
}
