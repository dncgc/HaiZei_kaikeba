/*************************************************************************
	> File Name: 477.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 05 Jan 2021 07:14:22 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

char s[105];

int func(char c) {
    switch (c) {
        case 'A' :
        case 'E' :
        case 'O' :
        case 'I' :
        case 'U' : return 1;
        default : return 0;
    }
    return 0;
}

int main() {
    cin >> s;
    int last, ans = 0;
    for (int i = 0; s[i]; i++) {
        if (func(s[i])) {
            last = i;
            break;
        }
    }
    for (int i = last + 1; s[i]; i++) {
        if (func(s[i])) {
            ans = max(ans, i - last);
            last = i;
        }
    }
    cout << ans << endl;
    return 0;
}
