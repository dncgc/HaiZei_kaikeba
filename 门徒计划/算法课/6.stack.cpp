/*************************************************************************
	> File Name: 6.stack.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 18 Mar 2021 08:45:49 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

class Stack {
public:
    Stack(int n = 100) {
        top = -1;
        data = new int[n];
    }
    void push(int x) {
        data[++top] = x;
        return ;
    }
    void pop() {
        if (empty()) return ;
        top -= 1;
        return ;
    }
    bool empty() {
        return top == -1;
    }
    int size() {
        return top + 1;
    }
    void output() {
        cout << "==========" << endl;
        for (int i = top; i >= 0; i--) {
            cout << " " << data[i] << endl;
        }
        cout << "=========" << endl;
        return ;
    }

private:
    int *data, top;
};

int main() {
    Stack s;
    string op;
    int val;
    while (cin >> op) {
        if (op == "push") {
            cin >> val;
            s.push(val);
        } else if (op == "pop") {
            s.pop();
        } else if (op == "size") {
            cout << "stack size : " << s.size() << endl;
        } else if (op == "output") {
            s.output();
        }
    }
    return 0;
}
