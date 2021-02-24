/*************************************************************************
	> File Name: floyd.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 24 Feb 2021 02:10:19 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

int n, m, s, arr[1005][1005];

int main() {
    memset(arr, 0x3F, sizeof(arr));
    cin >> n >> m >> s;
    for (int i = 1; i <= n; i++) {
        arr[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int s1, e, v;
        cin >> s1 >> e >> v;
        arr[s1][e] = min(arr[s1][e], v);
        arr[e][s1] = min(arr[e][s1], v);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (arr[s][i] != 0x3F3F3F3F) {
            cout << arr[s][i] << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}
