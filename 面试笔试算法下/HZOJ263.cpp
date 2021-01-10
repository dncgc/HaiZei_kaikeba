/*************************************************************************
	> File Name: HZOJ263.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sun 10 Jan 2021 03:05:55 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int a[30], s[30], top;

bool is_valid(int *a, int n) {
    int j = 0;
    top = -1;
    for (int i = 0; i < n; i++) {
        while (j < a[i]) { s[++top] = (++j); }
        if (top == -1 || s[top] - a[i]) return false;
        --top;
    }
    return true;
}

int main() {
    int n, ans = 20;
    cin >> n;
    for (int i = 0; i < n; i++) a[i] = i + 1;
    do {
        if (!is_valid(a, n)) continue;
        for (int i = 0; i < n; i++) {
            cout << a[i];
        }
        cout << endl;
        --ans;
    } while (ans && next_permutation(a, a + n));
    return 0;
}
