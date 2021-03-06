/*************************************************************************
	> File Name: 47.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 06 Mar 2021 10:41:12 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int n, vall, v[105], w[105], ans[105][10005];

int main() {
    cin >> vall >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= vall; j++) {
            if (j < v[i]) ans[i][j] = ans[i - 1][j];
            else ans[i][j] = max(ans[i - 1][j], ans[i - 1][j - v[i]] + w[i]);
        }
    }
    cout << ans[n][vall] << endl;
    return 0;
}
