/*************************************************************************
	> File Name: 166.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 27 Feb 2021 05:03:08 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1, s2;
    int n;
    cin >> s1 >> n >> s2;
    if (s1.length() > 100) cout << 100 << endl;
    else cout << s1.length() << endl;
    s1.insert(n - 1, s2);
    cout << s1 << endl;
    cout << s1.length() - s1.rfind("x") << endl;
    return 0;
}
