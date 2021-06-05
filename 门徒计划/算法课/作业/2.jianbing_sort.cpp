/*************************************************************************
	> File Name: 2.jianbing_sort.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 19 Mar 2021 10:17:19 PM CST
 ************************************************************************/

#include <iostream>

#define swap(a, b) {\
    __typeof(a) _a = a;\
    a = b, b = _a;\
}

int num[20], ind[20], ans[40];

void update(int n) {
    for (int i = n, j = 1; i > j; i--, j++) {
        ind[num[i]] = j;
        ind[num[j]] = i;
        swap(num[i], num[j]);
    }
    return ;
}

int main() {
    int cnt = 1;
    while (std::cin >> num[cnt]) ind[num[cnt]] = cnt, cnt += 1;
    int n = 1;
    while (--cnt > 1) {
        // if (ind[cnt] == cnt) continue;
        if (ind[cnt] != 1) ans[n++] = ind[cnt], update(ind[cnt]);
        if (cnt != 1) ans[n++] = cnt, update(cnt);
    }
    for (int i = 1; i < n; i++) {
        std::cout << ans[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
