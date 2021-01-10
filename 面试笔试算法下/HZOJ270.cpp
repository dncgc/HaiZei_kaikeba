/*************************************************************************
	> File Name: HZOJ270.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sun 10 Jan 2021 09:14:01 PM CST
 ************************************************************************/

#include <iostream>
#include <climits>
using namespace std;
#define MAX_N 300000
int s[MAX_N + 5], n, m;
int q[MAX_N + 5], head, tail;

void read() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] += s[i - 1];
    }
    return ;
}

int solve() {
    int ans = INT_MIN;
    head = tail = 0;
    q[tail++] = 0;
    for (int i = 1; i <= n; i++) {
        if (i - q[head] > m) head++;
        ans = max(ans, s[i] - s[q[head]]);
        while (tail - head && s[q[tail - 1]] > s[i]) --tail;
        q[tail++] = i;
    }
    return ans;
}

int main() {
    read();
    cout << solve() << endl;
    return 0;
}
