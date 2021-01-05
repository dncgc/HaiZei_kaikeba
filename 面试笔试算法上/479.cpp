/*************************************************************************
	> File Name: 479.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 05 Jan 2021 07:28:47 PM CST
 ************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

int ans11[10000][2], ans21[10000][2], ind11, ind21;

void print() {
    for (int i = 0; i <= ind11; i++) {
        cout << ans11[i][0] << ":" << ans11[i][1] << endl;
    }
    cout << endl;
    for (int i = 0; i <= ind21; i++) {
        cout << ans21[i][0] << ":" << ans21[i][1] << endl;
    }
}

int main() {
    char s[55];
    while (cin >> s) {
        for (int i = 0; s[i]; i++) {
            if (s[i] == 'E') {
                print();
                return 0;
            }
            if (s[i] == 'W') {
                ans11[ind11][0]++;
                ans21[ind21][0]++;
            } else {
                ans11[ind11][1]++;
                ans21[ind21][1]++;
            }
            if ((ans11[ind11][0] >= 11 || ans11[ind11][1] >= 11) && abs(ans11[ind11][0] - ans11[ind11][1]) >= 2) {
                ind11++;
            }
            if ((ans21[ind21][0] >= 21 || ans21[ind21][1] >= 21) && abs(ans21[ind21][0] - ans21[ind21][1]) >= 2) {
                ind21++;
            }
        }
    }
    return 0;
}
