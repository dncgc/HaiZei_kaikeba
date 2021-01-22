/*************************************************************************
	> File Name: 396.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 22 Jan 2021 02:37:44 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

struct Node {
    int x, y;
};
queue<Node> que;
int n, dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int mmap[35][35];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> mmap[i][j];
        }
    }
    que.push(Node{0, 0});
    mmap[0][0] = 3;
    while (!que.empty()) {
        Node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int xx = temp.x + dir[i][0];
            int yy = temp.y + dir[i][1];
            if (xx < 0 || yy < 0 || xx > n + 1 || yy > n + 1 || mmap[xx][yy] != 0) continue;
            que.push(Node{xx, yy});
            mmap[xx][yy] = 3;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            j == 1 || cout << " ";
            if (mmap[i][j] == 3) cout << 0;
            else if (mmap[i][j] == 0) cout << 2;
            else cout << 1;
        }
        cout << endl;
    }
    return 0;
}
