/*************************************************************************
	> File Name: 47_2.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 06 Mar 2021 11:05:35 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int n, vall, v[105], w[105], ans[10005];

int main() {
    cin >> vall >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = vall; j >= v[i]; j--) {
            ans[j] = max(ans[j], ans[j - v[i]] + w[i]);
        }
    }
    cout << ans[vall] << endl;
    return 0;
}
