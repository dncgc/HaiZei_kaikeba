/*************************************************************************
	> File Name: 518.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 09 Jan 2021 11:49:59 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int x, ans = 0, day = 0;
    scanf("%d", &x);
    for (int i = 1; i <= x; i++) {
        for (int j = i; j > 0; j--) {
            ans += i;
            if (++day == x) {
                printf("%d\n", ans);
                return 0;
            }
        }
    }
    return 0;
}
