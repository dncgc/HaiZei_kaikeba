/*************************************************************************
	> File Name: 378.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 14 Jan 2021 08:25:46 PM CST
 ************************************************************************/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    stack<char> sta;
    int flag = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            sta.push(s[i]);
        } else if (s[i] == ')') {
            if (!sta.empty() && sta.top() == '(') {
                sta.pop();
            } else {
                flag = 1;
                break;
            }
        } else if (s[i] == ']') {
            if (!sta.empty() && sta.top() == '[') {
                sta.pop();
            } else {
                flag = 1;
                break;
            }   
        } else if (s[i] == '}') {
            if (!sta.empty() && sta.top() == '{') {
                sta.pop();
            } else {
                flag = 1;
                break;
            }   
        }
    }
    if (!sta.empty()) {
        flag = 1;
    }
    if (flag) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
    return 0;
}
