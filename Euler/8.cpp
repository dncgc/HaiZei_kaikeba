/*************************************************************************
	> File Name: 8.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 04 Feb 2021 09:34:27 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    long long ans = 1;
    int l = 0, r = 0, cnt = 0;
    cin >> str;
    while (r < 13) {
        ans *= str[r++] - '0';
    }
    long long t = ans;
    while(str[r]) {
        if (str[l] == 0) cnt--;
        r++, l++;
        if (str[r] == 0) cnt++;
        if (str[r] != '0') t *= str[r] - '0';
        if (str[l - 1] != '0') t /= str[l - 1] - '0';
        if (!cnt) ans = max(ans, t);
    }
    cout << ans << endl;
    return 0;
}
