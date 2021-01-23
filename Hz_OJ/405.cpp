/*************************************************************************
	> File Name: 405.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 23 Jan 2021 11:21:59 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int n, m, k, mmap[3005][3005], cnt = 1;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
char s[3005];
vector<int> v;

void dfs(int x, int y) {
    int val = !mmap[x][y];
    mmap[x][y] = cnt;
    v[cnt]++;
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if (xx < 1 || yy < 1 || xx > n || yy > m || 
            mmap[xx][yy] != val) continue;
        dfs(xx, yy);
    }
}

int main() {
    v.push_back(0);
    v.push_back(0);
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s);
        for (int j = 1; j <= m; j++) {
            mmap[i][j] = s[j - 1] - '0';
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (mmap[i][j] > 1) continue;
            v.push_back(0);
            ++cnt;
            dfs(i, j);
        }
    }
    for (int i = 0; i < k; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", v[mmap[x][y]]);
    }
    return 0;
}
