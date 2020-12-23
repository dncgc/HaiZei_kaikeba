/*************************************************************************
	> File Name: euler8.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 22 Dec 2020 07:27:15 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    char num[1005];
    cin >> num;
    long long ans = 0, now = 1, cnt = 0;
    for (int i = 0; i < 1000; i++) {
        if (i < 13) {
            now *= num[i] - '0';
        } else {
            if (num[i] == '0') {
                cnt++;
            } else {
                now *= num[i] - '0';
            }
            if (num[i - 13] == '0') {
                cnt--;
            } else {
                now /= num[i - 13] - '0';
            }
        }
        if (cnt == 0) {
            ans = max(ans, now);
        }
    }
    cout << ans << endl;
    return 0;
}
