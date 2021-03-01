/*************************************************************************
	> File Name: astar.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon 01 Mar 2021 11:04:57 AM CST
 ************************************************************************/

#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct node {
    int x, y, step;
    double h;
    bool operator< (const node &b) const {
        return this->step + this->h > b.step + b.h;
    }
};

int n, m, sx, sy, ex, ey, cnt, prex[2005][2005], prey[2005][2005];
int dir[8][2] = {0, 1, 1, 0, 0, -1, -1, 0, 1, 1, 1, -1, -1, 1, -1, -1};
char mmap[2005][2005];

double func(int x, int y) {
    int a = ex - x, b = ey - y;
    return sqrt(a * a + b * b);
}

void p() {
    cout << "-------------------------------" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << mmap[i][j];
            if (mmap[i][j] == 'x') {
                mmap[i][j] = 'X';
            }
        }
        cout << endl;
    }
    cout << "+++++++++++++++++++++++++++++++" << endl;
}

void fin(int x, int y) {
    if (mmap[x][y] == 'S') {
        return ;
    }
    mmap[x][y] = 'o';
    fin(prex[x][y], prey[x][y]);
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
    priority_queue<node> que;
    que.push((node){sx, sy, 0, func(sx, sy)});
    while (!que.empty()) {
        node temp = que.top();
        que.pop();
        for (int i = 0; i < 8; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (mmap[x][y] == 'T') {
                cout << temp.step + 1 << endl;
                fin(temp.x, temp.y);
                p();
                return 0;
            }
            if (mmap[x][y] == '.') {
                mmap[x][y] = 'x';
                que.push((node){x, y, temp.step + 1, func(x, y)});
                prex[x][y] = temp.x;
                prey[x][y] = temp.y;
                cnt++;
                if (cnt % 10 == 0) {
                    p();
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
