/*************************************************************************
	> File Name: 575.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 14 Jan 2021 08:53:12 PM CST
 ************************************************************************/

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    int n, k;
    unordered_map<string, int> m;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string t;
        int t2;
        cin >> t >> t2;
        m[t] = t2;
    }
    cin >> k;
    for (int i = 0; i < k; i++) {
        string t;
        cin >> t;
        cout << m[t] << endl;
    }

    return 0;
}
