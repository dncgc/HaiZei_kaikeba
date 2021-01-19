/*************************************************************************
	> File Name: 572.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 19 Jan 2021 09:20:15 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;

#define MAX_N 400000

int n;
long long va[MAX_N + 5], vb[MAX_N + 5];
priority_queue<long long> pq;

int push_pop(long long num) {
    pq.push(num);
    if (pq.size() > n) {
        long long t = pq.top();
        pq.pop();
        if (num == t) return 0;
    }
    return 1;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", va + i);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", vb + i);
    }
    for (int i = 0; i < n; i++) {
        if (!push_pop(va[i] + vb[0])) break;
        for (int j = 1; j < n; j++) {
            if (!push_pop(va[i] + vb[j])) break;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        va[i] = pq.top();
        pq.pop();
    }
    for (int i = 0; i < n; i++) {
        printf("%lld\n", va[i]);
    }

    return 0;
}
