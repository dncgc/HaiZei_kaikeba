/*************************************************************************
	> File Name: luogu1507.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sun 07 Mar 2021 10:52:00 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int n, vall, mall, v[50], m[50], w[50], ans[50][405][405];
int a2[405][405];

int main() {
    cin >> vall >> mall >> n;
    for (int i = 1; i <= n; i++) {
        cin >> v[i] >> m[i] >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= vall; j++) {
            for (int k = 1; k <= mall; k++) {
                if (j < v[i] || k < m[i]) {
                    ans[i][j][k] = ans[i - 1][j][k];
                } else {
                    ans[i][j][k] = max(ans[i - 1][j][k], ans[i - 1][j - v[i]][k - m[i]] + w[i]);
                }
            }
        }
    }
    cout << ans[n][vall][mall] << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = vall; j >= v[i]; j--) {
            for (int k = mall; k >= m[i]; k--) {
                a2[j][k] = max(a2[j][k], a2[j - v[i]][k - m[i]] + w[i]);
            }
        }
    }
    cout << a2[vall][mall] << endl;
    return 0;
}
