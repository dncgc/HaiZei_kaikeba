/*************************************************************************
	> File Name: 520.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sun 10 Jan 2021 11:35:57 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

long long Sum(long long a, long long b) {
    return (a + b) * (b - a + 1) >> 1;
}

int main() {
    int a, max_a;
    scanf("%d", &a);
    max_a = 10 * a;
    for (int i = a; i < max_a; i++) {
        int l = i + 1, r = max_a;
        long long sum = Sum(1, i - 1);
        while (l <= r) {
            int mid = (l + r) >> 1;
            long long SUM = Sum(i + 1, mid);
            if (sum == SUM) {
                printf("%d %d\n", i, mid);
                return 0;
            } else if (sum < SUM) r = mid - 1;
            else l = mid + 1;
        }
    }
    return 0;
}
