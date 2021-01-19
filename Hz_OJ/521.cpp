/*************************************************************************
	> File Name: 521.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 19 Jan 2021 11:32:31 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;

int n, r, x[35], ans[35], mark[35], an;

int is_prime(int num) {
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void compute() {
    int num = 0;
    for (int i = 1; i <= r; i++) {
        num += x[ans[i]];
    }
    //if (is_prime(num)) an++;
    an++;
    return ;
}

void func(int cnt) {
    if (cnt == r + 1) {
        compute();
        return ;
    }
    for (int i = 1; i <= n; i++) {
        if (!mark[i]) {
            ans[cnt] = i;
            mark[i] = 1;
            func(cnt + 1);
            mark[i] = 0;
        }
    }
    return ;
}

int main() {
    scanf("%d%d", &n, &r);
    for (int i = 1; i <= n; i++) {
        scanf("%d", x + i);
    }
    func(1);
    printf("%d\n", an);
    return 0;
}
