/*************************************************************************
	> File Name: 382.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 14 Jan 2021 08:39:08 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    queue<int> que;
    for (int i = 1; i <= n; i++) {
        que.push(i);
    }
    while (que.size() != 1) {
        for (int i = 1; i < m; i++) {
            que.push(que.front());
            que.pop();
        }
        que.pop();
    }
    cout << que.front() << endl;
    return 0;
}
