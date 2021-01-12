/*************************************************************************
	> File Name: HZOJ329.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 12 Jan 2021 10:46:52 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 100000
int c[MAX_N + 5];
#define lowbit(x) (x & -x)
void add(int i, int x, int n) {
    while (i <= n) {
        c[i] += x;
        i += lowbit(i);
    }
    return ;
}

int query(int i) {
    int sum = 0;
    while (i) {
        sum += c[i];
        i -= lowbit(i);
    }
    return sum;
}

int main() {
    int m, n, pre = 0, a;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        add(i, a - pre, n);
        pre = a;
    }
    cin >> m;
    char s[10];
    int l, r, x;
    for (int i = 0; i < m; i++) {
        cin >> s;
        switch (s[0]) {
            case 'C': {
                cin >> l >> r >> x;
                add(l, x, n);
                add(r + 1, -x, n);
            } break;
            case 'Q': {
                cin >> x;
                cout << query(x) << endl;
            } break;
        }
    }
    return 0;
}
