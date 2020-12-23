/*************************************************************************
	> File Name: euler1.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 22 Dec 2020 06:20:38 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    /*
    int ans = 0;
    for (int i = 3; i < 1000; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            ans += i;
        }
    }
    cout << ans << endl;
    */
    int a3 = (3 + 999) * 333 / 2;
    int a5 = (5 + 995) * 199 / 2;
    int a15 = (15 + 990) * 66 / 2;
    cout << a3 + a5 - a15 << endl;
    return 0;
}
