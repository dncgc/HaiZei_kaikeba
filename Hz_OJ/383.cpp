/*************************************************************************
	> File Name: 383.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 13 Jan 2021 11:35:56 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;
#define MAX_N 1000
int x, y, n;
queue<int> m, w;

int main() {
    cin >> x >> y >> n;
    for (int i = 1; i <= x; i++) {
        m.push(i);
    }
    for (int i = 1; i <= y; i++) {
        w.push(i);
    }
    for (int i = 0; i < n; i++) {
        cout << m.front() << " " << w.front() << endl;
        m.push(m.front()), m.pop();
        w.push(w.front()), w.pop();
    }
    return 0;
}
