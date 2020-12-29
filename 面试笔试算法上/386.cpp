/*************************************************************************
	> File Name: 386.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 29 Dec 2020 06:39:52 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

struct node {
    int cnt, num;
};

bool cmp(const node &a, const node &b) {
    return a.num < b.num;
}

int n, m;
node wm[100005];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &wm[i].num);
        wm[i].cnt = i + 1;
    }
    sort(wm, wm + n, cmp);
    for (int i = 0; i < m; i++) {
        int t, l = 0, r = n - 1;
        scanf("%d", &t);
        while (l <= r) {
            int mid = (l + r) / 2;
            if (wm[mid].num == t) {
                printf("%d\n", wm[mid].cnt);
                t = -1;
                break;
            }
            if (wm[mid].num > t) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        if (t != -1) {
            printf("0\n");
        }
    }
    return 0;
}
