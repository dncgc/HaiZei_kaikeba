/*************************************************************************
	> File Name: 503.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 08 Jan 2021 09:59:19 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int w, n, num[30005], ans;

int main() {
    scanf("%d%d", &w, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", num + i);
    }
    sort(num, num + n);
    for (int i = n - 1, j = 0; i >= 0; i --) {
        if (num[i] == 0) break;
        if (num[i] + num[j] > w) ans++;
        else {
            ans++;
            num[j++] = 0;
        }
    }
    printf("%d\n", ans);
    return 0;
}
