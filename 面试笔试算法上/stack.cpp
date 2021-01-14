/*************************************************************************
	> File Name: stack.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 14 Jan 2021 06:34:41 PM CST
 ************************************************************************/

#include <iostream>
#include <stack>
using namespace std;

struct node{
    int a, b;
};

int main() {
    stack<int> sta;
    sta.push(5);
    sta.push(3);
    sta.push(10);
    while (!sta.empty()) {
        cout << sta.top() << endl;
        sta.pop();
    }
    //cout << sta.top() << endl;//非法操作
    stack<node> s2;
    node t;
    t.a = 5;
    t.b = 6;
    s2.push(t);
    s2.push((node){8, 9});//c++11
    while (!s2.empty()) {
        node temp = s2.top();
        s2.pop();
        cout << temp.a << " " << temp.b << endl;
    }
    return 0;
}
