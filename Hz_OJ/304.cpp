/*************************************************************************
	> File Name: 304.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 22 Jan 2021 02:05:58 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

struct Node {
    int x, y, step;
};
queue<Node> que;
int n, m, dir[8][2] = {1, 2, 1, -2, 2, 1, 2, -1, -1, 2, -1, -2, -2, 1, -2, -1};
char mmap[200][200];

int main() {
    cin >> m >> n;
    for (int i = 5; i < n + 5; i++) {
        for (int j = 5; j < m + 5; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == 'K') {
                que.push((Node){i, j, 0});
                mmap[i][j] = 0;
            }
        }
    }
    while(!que.empty()) {
        Node temp = que.front();
        que.pop();
        for (int i = 0; i < 8; i++) {
            int xx = temp.x + dir[i][0];
            int yy = temp.y + dir[i][1];
            if (mmap[xx][yy] == 'H') {
                cout << temp.step + 1 << endl;
                return 0;
            }
            if (mmap[xx][yy] == '.') {
                que.push((Node){xx, yy, temp.step + 1});
                mmap[xx][yy] = 0;
            } else continue;
        }
    }

    return 0;
}
