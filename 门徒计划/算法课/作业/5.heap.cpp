/*************************************************************************
	> File Name: 5.heap.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 10 Apr 2021 09:07:31 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

priority_queue<long long> q;

int main() {
    long long num;
    while (cin >> num) q.push(num);
    while (q.size() >= 6) {
        long long a = q.top(); q.pop();
        long long b = q.top(); q.pop();
        if (a - b) q.push(a - b);
    }
    vector<int> v;
    while (!q.empty()) {
        v.push_back(q.top());
        q.pop();
    }
    for (int i = v.size() - 1; i >= 0; i--) cout << v[i];
    cout << endl;
    return 0;
}
