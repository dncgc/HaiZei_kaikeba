/*************************************************************************
	> File Name: 404.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 22 Jan 2021 04:37:40 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;
#define REVERSE(a) (a == '0' ? '1' : '0')

struct Node {
    int x, y, cnt;
};
int ans, n, m, x, y, dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
queue<Node> que;
char mmap[3005][3005];

void dfs(int xx, int yy) {
    char val = REVERSE(mmap[xx][yy]);
    mmap[xx][yy] = '2';
    ans++;
    for (int i = 0; i < 4; i++) {
        int xxx = xx + dir[i][0];
        int yyy = yy + dir[i][1];
        if (xxx < 1 || yyy < 1 || xxx > n || yyy > m || mmap[xxx][yyy] != val) continue;
        dfs(xxx, yyy);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
        }
    }
    cin >> x >> y;
    dfs(x, y);
    cout << ans << endl;
    return 0;
}
