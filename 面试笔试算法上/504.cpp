/*************************************************************************
	> File Name: 504.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 05 Jan 2021 08:55:01 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;



int main() {
    string s;
    int n;
    cin >> s >> n;
    for (int i = 0; i < n; i++) {
        int ind = s.size() - 1;
        for (int j = 0; j < s.size() - 1; j++) {
            if (s[j] > s[j + 1]) {
                ind = j;
                break;
            }
        }
        s.replace(ind, 1, "");
    }
    int flag = 1;
    for (int i = 0; i < s.size(); i++) {
        if (flag == 0) {
            cout << s[i];
        } else {
            if (s[i] != '0') {
                cout << s[i];
                flag = 0;
            }
        }
    }
    if (flag == 1) {
        cout << 0;
    }
    cout << endl;
    return 0;
}
