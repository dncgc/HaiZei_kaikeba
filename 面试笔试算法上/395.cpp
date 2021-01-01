/*************************************************************************
	> File Name: 395.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 01 Jan 2021 07:29:22 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int m, k, num[505], dis[1005];

int func(int x) {
    int add = 0, ans = 1;
    for (int i = 1; i <= m; i++) {
        add += num[i];
        if (add > x) {
            i--;
            add = 0;
            ans++;
        }
    }
    return ans;
}

int main() {
    int l = 0, r = 0;
    scanf("%d%d", &m, &k);
    for (int i = 1; i <= m; i++) {
        scanf("%d", num + i);
        r += num[i];
        l = num[i] > l ? num[i] : l;
    }
    while (l != r) {
        int mid = (l + r) >> 1;
        if (func(mid) <= k) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    int add = 0, ind = m;
    /*
    for (int i = 1; i <= m; i++) {
        add += num[i];
        if (add > l) {
            printf("%d %d\n", ind, i - 1);
            ind = i;
            i--;
            add = 0;
        }
    }*/
    for (int i = m; i > 0; i--) {
        add += num[i];
        if (add > l) {
            dis[++dis[0]] = i + 1;
            dis[++dis[0]] = ind;
            ind = i;
            i++;
            add = 0;
        }
    }
    dis[++dis[0]] = 1;
    dis[++dis[0]] = ind;
    for (int i = dis[0]; i > 0; i -= 2) {
        printf("%d %d\n", dis[i - 1], dis[i]);
    }
    return 0;
}
