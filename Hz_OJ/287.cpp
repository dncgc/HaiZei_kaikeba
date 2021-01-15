/*************************************************************************
	> File Name: 287.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 15 Jan 2021 01:38:18 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

int main() {
    int n, ans = 0;
    priority_queue<int, vector<int>, greater<int> > pq;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int m;
        scanf("%d" ,&m);
        pq.push(m);
    }
    while (pq.size() != 1) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.push(a + b);
        ans += a + b;
    }
    printf("%d\n", ans);
    return 0;
}
