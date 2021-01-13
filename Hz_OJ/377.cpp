/*************************************************************************
	> File Name: 377.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 13 Jan 2021 11:42:33 PM CST
 ************************************************************************/

#include <iostream>
#include <stack>
using namespace std;
#define MAX_N 300
char str[MAX_N + 5];
stack<char> s; 

int main() {
    cin >> str;
    for (int i = 0; str[i] != '@'; i++) {
        if (str[i] == '(') s.push(str[i]);
        if (str[i] == ')') {
            if (!s.empty()) s.pop();
            else {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    if (s.empty()) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
