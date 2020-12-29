/*************************************************************************
	> File Name: 387.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 29 Dec 2020 07:19:07 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct node {
    int cnt, num;
};

bool cmp(const node &a, const node &b) {
    return a.num < b.num;
}

node wm[100005];
int n, m;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &wm[i].num);
        wm[i].cnt = i + 1;
    }
    wm[n++].cnt = 0, wm[n].num = 2000000000;
    sort(wm, wm + n, cmp);
    for (int i = 0; i < m; i++) {
        int t, l = 0, r = n - 1;
        scanf("%d", &t);
        while (l != r) {
            int mid = (l + r) >> 1;
            if (wm[mid].num >= t) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        printf("%d\n", wm[l].cnt);
    }
    return 0;
}
