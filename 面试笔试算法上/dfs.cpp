/*************************************************************************
	> File Name: dfs.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 21 Jan 2021 06:22:51 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int n, m, sx, sy;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char mmap[105][105];

int func(int x, int y) {//以x，y为起点，能否走到终点
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        /*
        if (xx == 0 || yy == 0 || xx > n || yy > m) {
            continue;
        }
        */
        if (mmap[xx][yy] == 'T') {
            return 1;
        }
        if (mmap[xx][yy] == '.') {
            mmap[xx][yy] = '#';
            if (func(xx, yy)) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == 'S') {
                sx = i;
                sy = j;
            }
        }
    }
    if (func(sx, sy)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
