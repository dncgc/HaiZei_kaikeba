/*************************************************************************
	> File Name: HZOJ44.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 06 Feb 2021 07:21:58 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 1000000
int n, len[MAX_N + 5];

int bs(int l, int r, int val) {
    while(l != r) {
        int mid = (l + r) >> 1;
        if (len[mid] < val) l = mid + 1;
        else r = mid;
    }
    return l;
}

int main() {
    scanf("%d", &n);
    int cnt = 1;
    for (int i = 0; i < n; i++) {
        len[cnt] = 0x7fff;
        int t;
        scanf("%d", &t);
        int ind = bs(1, cnt, t);
        if (len[ind] == 0x7fff) len[cnt++] = t;
        if (len[ind] > t) len[ind] = t;
    }
    printf("%d\n", cnt - 1);
    return 0;
}
