/*************************************************************************
	> File Name: 388.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 30 Dec 2020 05:06:13 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

struct node {
    int num, ind;
};
node mnum[100005], nnum[100005];

bool cmp1(const node &a, const node &b) {
    return a.num < b.num;
}

bool cmp2(const node &a, const node &b) {
    return a.ind < b.ind;
}

int main() {
    int m, n, j, cnt = 0;
    long long ans = 0;
    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; i++) {
        scanf("%d", &mnum[i].num);
        mnum[i].ind = i;
    }
    sort(mnum, mnum + m, cmp1);
    for (int i = 0; i < n; i++) {
        scanf("%d", &j);
        int l = 0, r = m - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (mnum[mid].num == j) {
                ans += j;
                nnum[cnt++] = mnum[mid];
                break;
            }
            else if (mnum[mid].num < j) l = mid + 1;
            else r = mid - 1;
        }
    }
    sort(nnum, nnum + cnt, cmp2);
    for (int i = 0; i < cnt; i++) {
        i && printf(" ");
        printf("%d", nnum[i].num);
    }
    printf("\n%lld\n", ans);
    return 0;
}
