/*************************************************************************
	> File Name: 3.stack.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon 22 Mar 2021 07:31:58 PM CST
 ************************************************************************/

#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    long long ans = 0;
    int cnt = 1;
    string str;
    while (cin >> str) {
        int t;
        if (str == "push") {
            cin >> t;
            s.push(t);
        } else {
            if (s.empty()) continue;
            t = s.top();
            s.pop();
            ans += (t * (cnt++));
        }
    }
    cout << ans << endl;
    return 0;
}
