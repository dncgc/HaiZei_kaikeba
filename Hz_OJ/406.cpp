/*************************************************************************
	> File Name: 406.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 22 Jan 2021 03:10:44 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int ans, n, m;
int dir[8][2] = {0, 1, 0, -1, 1, 0, 1, -1, 1, 1, -1, 0, -1, -1, -1, 1};
char mmap[2005][2005];

void dfs(int x, int y) {
    mmap[x][y] = 0;
    for (int i = 0; i < 8; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (mmap[xx][yy] != '#') continue;
        dfs(xx, yy);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mmap[i][j] == '#') {
                ans++;
                dfs(i, j);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
