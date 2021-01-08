/*************************************************************************
	> File Name: 519.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 08 Jan 2021 08:56:27 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    long long a, b, ans = 0;
    cin >> a >> b;
    for (int i = 0; i <= 9; i++) { //1个数
        for (int j = 0; j <= 9; j++) { // 1堆数
            if (i == j) continue;
            for (int k = 3; k <= 17; k++) { //数长
                for (int l = 1; l <= k; l++) { //1个数的位置
                    if (l == 1 && i == 0) continue;
                    if (l != 1 && j == 0) break;
                    long long t = 0;
                    for (int m = 1; m <= k; m++) { //求数
                        if (m == l) {
                            t = t * 10 + i;
                        } else {
                            t = t * 10 + j;
                        }
                    }
                    if (t >= a && t <= b) {
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
