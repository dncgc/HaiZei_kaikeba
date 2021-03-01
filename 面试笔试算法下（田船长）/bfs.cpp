/*************************************************************************
	> File Name: bfs.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon 01 Mar 2021 10:45:49 AM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

struct node {
    int x, y, step;
};

int n, m, cnt, sx, sy, ex, ey;
int dir[8][2] = {0, 1, 1, 0, 0, -1, -1, 0, 1, 1, 1, -1, -1, 1, -1, -1};
char mmap[2005][2005];

void p() {
    cout << "----------------------------------" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << mmap[i][j];
            if (mmap[i][j] == 'x') {
                mmap[i][j] = 'X';
            }
        }
        cout << endl;
    }
    cout << "----------------------------------" << endl;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == 'S') {
                sx = i, sy = j;
            }
            if (mmap[i][j] == 'T') {
                ex = i, ey = j;
            }
        }
    }
    queue<node> que;
    que.push((node){sx, sy, 0});
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 8; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (mmap[x][y] == 'T') {
                cout << temp.step + 1 << endl;
                return 0;
            }
            if (mmap[x][y] == '.') {
                mmap[x][y] = 'x';
                cnt++;
                if (cnt % 50 == 0) {
                    p();
                }
                que.push((node){x, y, temp.step + 1});
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
