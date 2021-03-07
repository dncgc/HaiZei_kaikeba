/*************************************************************************
	> File Name: 48.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sun 07 Mar 2021 11:37:54 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int n, vall, v[10005], w[10005], ans[10005][10005];

int main() {
    cin >> n >> vall;
    for(int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];
    }
    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= vall; j++) {
            if (j < v[i]) ans[i][j] = ans[i - 1][j];
            else ans[i][j] = max(ans[i - 1][j], ans[i][j - v[i]] + w[i]);
        }
    }
    cout << ans[n][vall] << endl;
    return 0;
}
