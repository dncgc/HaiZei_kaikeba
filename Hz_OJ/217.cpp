/*************************************************************************
	> File Name: 217.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 30 Dec 2020 08:46:15 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int num[100005];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", num + i);
    }
    sort(num, num + n);
    int ind = (n - 1) >> 1;
    while (ind) {
        if (num[ind - 1] != num[ind]) break;
        ind--;
    }
    printf("%d %d\n", num[ind], n - ind);
    return 0;
}
