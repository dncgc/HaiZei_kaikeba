/*************************************************************************
	> File Name: 287.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 27 Feb 2021 05:29:04 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

struct CMP {
public:
    bool operator()(int a, int b) {
        return a > b;
    }
};

int main() {
    priority_queue<int, vector<int>, CMP> q; //CMP 可以改为greater<int>
    int n, sum = 0;
    cin >> n;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        q.push(a);
    }
    for (int i = 1; i < n; i++) {
        int a = q.top(); q.pop();
        int b = q.top(); q.pop();
        sum += a + b;
        q.push(a + b);
    }
    cout << sum << endl;
    //while (!q.empty()) {
    //    cout << q.top() << endl;
    //    q.pop();
    //}
    return 0;
}
