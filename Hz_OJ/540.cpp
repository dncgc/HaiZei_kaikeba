/*************************************************************************
	> File Name: 540.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 30 Jan 2021 09:46:48 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;


int n, x, ans, m[45];

int dfs(int ind) {
    if (ans > x) return 0;
    if (ans == x) {
        printf("YES\n");
        return 1;
    }
    for (int i = ind; i <= n; i++) {
        ans += m[i];
        if (dfs(i + 1)) return 1;
        ans -= m[i];
    }
    return 0;
}

int main() {
    while (~scanf("%d%d", &n, &x)) {
        for (int i = 1; i <= n; i++) {
            scanf("%d", m + i);
        }
        if (!dfs(1)) printf("NO\n");
    }
    return 0;
}
