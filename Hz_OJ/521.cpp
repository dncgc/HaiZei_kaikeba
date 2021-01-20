/*************************************************************************
	> File Name: 521.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 19 Jan 2021 11:32:31 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;
#define MAX_N 3000000

int n, r, x[35], ans, sum;
int prime[MAX_N] = {1, 1};
// p[MAX_N];
/*
void init_prime() {
    for (int i = 2; i < MAX_N; i++) {
        if (!prime[i]) p[++p[0]] = i;
        for (int j = 1; j <= p[0]; j++) {
            int t = p[j] * i;
            if (t < MAX_N) prime[t] = 1;
            else break;
            if (i % p[j] == 0) break;
        }
    }
    return ;
}
*/
void init_prime() {
    for (int i = 2; i * i < MAX_N; i++) {
        if (!prime[i]) {
            for (int j = i * i; j < MAX_N; j += i) {
                prime[j] = 1;
            }
        }
    }
    return ;
}

/*
void compute() {
    int num = 0;
    for (int i = 1; i <= r; i++) {
        num += x[ans[i]];
    }
    if (!prime[num]) an++;
    return ;
}
*/

void func(int s, int cnt, int left) {
    if (!left) {
        if (!prime[sum]) ans++;
        return ;
    }
    for (int i = s; i <= n - r + cnt; i++) {
        //ans[cnt] = i;
        sum += x[i];
        func(i + 1, cnt + 1, left - 1);
        sum -= x[i];
    }
    return ;
}

int main() {
    init_prime();
    scanf("%d%d", &n, &r);
    for (int i = 1; i <= n; i++) {
        scanf("%d", x + i);
    }
    func(1, 1, r);
    printf("%d\n", ans);
    return 0;
}
