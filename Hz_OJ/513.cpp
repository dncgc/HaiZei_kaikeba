/*************************************************************************
	> File Name: 513.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 09 Jan 2021 11:41:10 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio> 
using namespace std;
int m, t, ans;

bool has_t(int val) {
    while (val) {
        if (val % 10 == t) return true;
        val /= 10;
    }
    return false;
}

int main() {
    scanf("%d%d", &m, &t);
    for (int i = 1; i <= m; i++) {
        if (has_t(i)) continue;
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}
