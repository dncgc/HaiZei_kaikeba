/*************************************************************************
	> File Name: HZOJ264.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sun 10 Jan 2021 04:22:55 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 100000
int h[MAX_N + 5], n;
int s[MAX_N + 5], top;
int l[MAX_N + 5], r[MAX_N + 5];

void read() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", h + i);
    }
    return ;
}

long long solve() {
    h[0] = h[n + 1] = -1;
    top = -1;
    s[++top] = 0;
    for (int i = 1; i <= n; i++) {
        while (top != -1 && h[s[top]] >= h[i]) --top;
        l[i] = s[top];
        s[++top] = i;
    }
    top = -1;
    s[++top] = n + 1;
    for (int i = n; i >= 1; i--) {
        while (top != -1 && h[s[top]] >= h[i]) --top;
        r[i] = s[top];
        s[++top] = i;
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, (long long)h[i] * (r[i] - l[i] - 1));
    }
    return ans;
}

int main() {
    read();
    printf("%lld\n", solve());
    return 0;
}
