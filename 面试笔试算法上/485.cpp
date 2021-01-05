/*************************************************************************
	> File Name: 485.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 05 Jan 2021 07:55:02 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int n, ans, num[105], avg, sum;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        sum += num[i];
    }
    avg = sum / n;
    for (int i = 0; i < n - 1; i++) {
        if (num[i] != avg) {
            ans++;
            num[i + 1] += num[i] - avg;
        }
    }
    cout << ans << endl;
    return 0;
}
