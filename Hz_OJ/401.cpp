/*************************************************************************
	> File Name: 401.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 22 Jan 2021 10:53:12 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

struct Node {
    int x, y, step;
};
int n, x, y;
int dir[12][2] = {2, 1, 2, -1, 1, 2, 1, -2, -1, 2, -1, -2, -2, 1, -2 ,-1, 2, 2, 2, -2, -2, 2, -2, -2};
int mmap[505][505];

void bfs(int xx, int yy) {
    queue<Node> que;
    que.push((Node){xx, yy, 0});
    mmap[xx][yy] = 1;
    while (!que.empty()) {
        Node temp = que.front();
        que.pop();
        for (int i = 0; i < 12; i++) {
            int xxx = temp.x + dir[i][0];
            int yyy = temp.y + dir[i][1];
            if (xxx < 1 || yyy < 1 || xxx > 500 || yyy > 500 || mmap[xxx][yyy] != 0) continue;
            que.push((Node){xxx, yyy, temp.step + 1});
            mmap[xxx][yyy] = temp.step + 1;
        }
    }
}

int main() {
    scanf("%d", &n);
    bfs(1, 1);
    mmap[1][1] = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &x, &y);
        printf("%d\n", mmap[x][y]);
    }
    return 0;
}
