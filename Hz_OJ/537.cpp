/*************************************************************************
	> File Name: 537.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 29 Jan 2021 08:12:40 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

#define Is_aeiou(a) (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')

int l, c, cnty, cntf, cnt;
char s[30], ans[20];

void func(int b, int r) {
    if (cnt == 25000) return ;
    if (b > l) {
        if (cnty > 0 && cntf > 1) {
            printf("%s\n", ans + 1);
            cnt++;
        }
        return ;
    }
    for (int i = r; i <= c; i++) {
        ans[b] = s[i];
        if (Is_aeiou(s[i])) {
            cnty++;
        } else {
            cntf++;
        }
        func(b + 1, i + 1);
        if (Is_aeiou(s[i])) {
            cnty--;
        } else {
            cntf--;
        }
    }
}

int main() {
    scanf("%d%d", &l, &c);
    for (int i = 1; i <= c; i++) {
        char str[5];
        scanf("%s", str);
        s[i] = str[0];
    }
    sort(s + 1, s + c + 1);
    func(1, 1);
    return 0;
}
