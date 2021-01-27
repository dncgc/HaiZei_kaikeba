/*************************************************************************
	> File Name: 303.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 27 Jan 2021 09:05:42 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;


struct node {
    int x, y, step;
};
int n, m, ans[1005][1005];
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char mmap[1005][1005];

int main() {
    queue<node> que;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> mmap[i][j];
            if (mmap[i][j] == '1') {
                que.push((node){i, j, 0});
                ans[i][j] = -1;
            }
        }
    }
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int x = temp.x + dir[i][0];
            int y = temp.y + dir[i][1];
            if (mmap[x][y] == 0 || ans[x][y] != 0) {
                continue;
            }
            ans[x][y] = temp.step + 1;
            que.push((node){x, y, ans[x][y]});
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            j == 1 || cout << " ";
            if (ans[i][j] == -1) {
                cout << 0;
            } else {
                cout << ans[i][j];
            }
        }
        cout << endl;
    }

    return 0;
}
