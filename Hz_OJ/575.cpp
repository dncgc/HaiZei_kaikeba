/*************************************************************************
	> File Name: 575.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 14 Jan 2021 11:53:58 AM CST
 ************************************************************************/

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
#define MAX_N 10000
int n, m, page;
string s;
unordered_map<string, int> dictionary;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s >> page;
        dictionary[s] = page;
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> s;
        cout << dictionary[s] << endl;
    }
    return 0;
}
