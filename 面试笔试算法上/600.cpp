/*************************************************************************
	> File Name: 600.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 31 Dec 2020 06:33:28 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int n, m, target, num[3005][3005];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &num[i][j]);
        }
    }
    scanf("%d", &target);
    int x = n, y = 1;
    while (x >= 1 && y <= m) {
        if (num[x][y] == target) {
            cout << x << " " << y << endl;
            return 0;
        }
        if (num[x][y] > target) {
            x--;
        } else {
            y++;
        }
    }
    cout << "not find" << endl;
    return 0;
}
