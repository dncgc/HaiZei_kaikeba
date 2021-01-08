/*************************************************************************
	> File Name: 515.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 08 Jan 2021 08:19:32 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int a, b, l, ta, tb;
double raw, now;

int main() {
    cin >> a >> b >> l;
    raw = (double)a / b;
    now = 99999999999;
    for (int i = 1; i <= l; i++) {
        for (int j = 1; j <= l; j++) {
            double t = (double)i / j;
            if (t > raw && now - raw > t - raw) {
                now = t;
                ta = i, tb = j;
            }
        }
    }
    cout << ta << " " << tb << endl;
    return 0;
}
