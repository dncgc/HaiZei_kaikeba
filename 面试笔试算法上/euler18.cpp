/*************************************************************************
	> File Name: euler18.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 24 Dec 2020 07:54:04 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int n, num[20][20];

int main() {
    n = 15;
    //避免数组越界，从（1，1）读入，不用判断边界了
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> num[i][j];
        }
    }
    /*
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            num[i][j] += max(num[i - 1][j - 1], num[i - 1][j]);
            ans = max(ans, num[i][j]);
        }
    }
    cout << ans << endl;
    */
    for (int i = n - 1; i > 0; i--) {
        for (int j = 1; j <= i; j++) {
            num[i][j] += max(num[i + 1][j], num[i + 1][j + 1]);
        }
    }
    cout << num[1][1] << endl;
    return 0;
}
