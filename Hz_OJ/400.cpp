/*************************************************************************
	> File Name: 400.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 22 Jan 2021 03:34:49 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Node {
    int x, y, step;
};
int x1, y1, x2, y2;
int dir[12][2] = {1, 2, 1, -2, 2, 1, 2, -1, -1, 2, -1, -2, -2, 1, -2, -1, 2, 2, 2, -2, -2, 2, -2, -2};

int bfs(int x, int y) {
    queue<Node> que;
    char mmap[505][505] = {0};
    que.push((Node){x, y, 0});
    mmap[x][y] = 1;
    if (x == 1 && y == 1) return 0;
    while (!que.empty()) {
        Node temp = que.front();
        que.pop();
        for (int i = 0; i < 12; i++) {
            int xx = temp.x + dir[i][0];
            int yy = temp.y + dir[i][1];
            if (xx < 1 || yy < 1 || xx > 500 || yy > 500 || mmap[xx][yy] != 0) continue;
            if (xx == 1 && yy == 1) return temp.step + 1;
            que.push((Node){xx, yy, temp.step + 1});
            mmap[xx][yy] = 1;
        }
    }
}

int main() {
    cin >> x1 >> y1 >> x2 >> y2;
    cout << bfs(x1, y1) << endl << bfs(x2, y2) << endl;
    return 0;
}
