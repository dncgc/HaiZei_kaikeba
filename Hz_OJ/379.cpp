/*************************************************************************
	> File Name: 379.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 14 Jan 2021 11:04:40 PM CST
 ************************************************************************/

#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int num, max;
};

int main() {
    int n, op, num, ma;
    stack<Node> s;
    cin >> n;
    for (int i = 0 ; i < n; i++) {
        cin >> op;
        switch (op) {
            case 0: {
                cin >> num;
                if (s.size()) ma = max(num, s.top().max);
                else ma = num;
                s.push((Node){num, ma});
            } break;
            case 1: {
                if (s.size()) s.pop();
            } break;
            case 2: {
                if (s.size()) {
                    cout << s.top().max << endl;
                } else {
                    cout << "0" << endl;
                }
            } break;
        }
    }
    return 0;
}
