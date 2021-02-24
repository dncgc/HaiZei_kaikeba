/*************************************************************************
	> File Name: arr.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 24 Feb 2021 01:46:38 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

int n, m, arr[105][105];

int main() {
    //0x3F3F3F3F 是10亿多，比较大，而且即使乘2也不会超过int表示范围
    memset(arr, 0x3F, sizeof(arr));
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int s, e, v;
        cin >> s >> e >> v;
        //arr[s][e] = v;
        arr[s][e] = min(v, arr[s][e]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] != 0x3F3F3F3F) {
                cout << arr[i][j] << " ";
            } else {
                cout << 0 << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
