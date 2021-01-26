/*************************************************************************
	> File Name: 游戏分组.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 26 Jan 2021 11:40:09 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

#define MAX_N 1000000
int fa[MAX_N + 5];
int get(int x) {
    return fa[x] = (x == fa[x] ? x : get(fa[x]));
}
void merge(int a, int b) {
    fa[get(a)] = get(b);
    return ;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) fa[i] = i;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        merge(a, b);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (fa[i] == i);
    }
    cout << ans << endl;
    return 0;
}
