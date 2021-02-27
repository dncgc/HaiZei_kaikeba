/*************************************************************************
	> File Name: 216.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 27 Feb 2021 05:14:26 PM CST
 ************************************************************************/

#include <iostream>
#include <map>
using namespace std;

int main() {
    string s;
    map<string, int> h;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        h[s.substr(3, s.size())] += 1;
    }
    for (auto iter = h.begin(); iter != h.end(); iter++) {
        for (int i = 0; i < iter->second; i++) {
            cout << iter->first << endl;
        }
    }
    return 0;
}
