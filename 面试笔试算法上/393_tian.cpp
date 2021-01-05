/*************************************************************************
	> File Name: 393_tian.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 05 Jan 2021 06:35:25 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

double num[10005], l, r;
int n, m;

int func2(double x) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += num[i] / x;
    }
    return cnt;
}

double func() {
    while (r - l > 0.00001) {
        double mid = (l + r) / 2;
        int s = func2(mid);
        if (s >= m) {
            l = mid;
        } else {
            r = mid;
        }
    }
    return r;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        r = max(r, num[i]);
    }
    double ans = func();
    cout << ans << endl;

    return 0;
}
