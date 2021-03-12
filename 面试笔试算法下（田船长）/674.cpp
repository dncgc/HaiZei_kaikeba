/*************************************************************************
	> File Name: 674.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 12 Mar 2021 08:41:20 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

int n, m, arr[105][105], in_degree[105], out_degree[105], ans;

int main() {
    memset(arr, 0x3f, sizeof(arr));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] != 0x3f3f3f3f) {
                out_degree[i]++;
                in_degree[j]++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] + out_degree[i] == n - 1) {
            ans++;
            //cout << i << " : " << in_degree[i] + 1 << endl;
        }
    }
    cout << ans << endl;
    return 0;
}
