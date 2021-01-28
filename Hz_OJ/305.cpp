/*************************************************************************
	> File Name: 305.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 28 Jan 2021 11:12:10 AM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x, y, step;
};
int n, m, x, y, ans;
int dir[8][2] = {0, 1, 1, 0, 0, -1, -1, 0, 1, 1, 1, -1, -1, 1, -1, -1};
char mmap[105][105];

int main() {
    queue<node> que;
    cin >> m >> n >> x >> y;
    for (int i = 1; i <= n; i++) {
        cin >> &mmap[i][1];
    }
    int t = x;
    x = n - y + 1;
    y = t;
    que.push((node){x, y, 0});
    mmap[x][y] = 'm';
    while (!que.empty()) {
        node temp = que.front();
        ans = temp.step;
        que.pop();
        for (int i = 0; i < 8; i++) {
            int xx = temp.x + dir[i][0];
            int yy = temp.y + dir[i][1];
            if (mmap[xx][yy] != '.') continue;
            mmap[xx][yy] = 'm';
            que.push((node){xx, yy, temp.step + 1});
        }
    }
    cout << ans << endl;
    return 0;
}
