/*************************************************************************
	> File Name: 392.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 01 Jan 2021 03:36:53 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int num[100005];
int a, b;

int func(int d) {
    int ans = 1, temp = num[0];
    for (int i = 1; i < a; i++) {
        if (num[i] - temp >= d) {
            ans++;
            temp = num[i];
        }
    }
    return ans;
}

int main() {
    scanf("%d%d", &a, &b);
    for (int i = 0; i < a; i++) {
        scanf("%d", num + i);
    }
    sort(num, num + a);
    int l = 1, r = num[a - 1] - num[0];
    while (l != r) {
        int mid = (l + r + 1) >> 1;
        if (func(mid) >= b) l = mid;
        else r = mid - 1;
    }
    printf("%d\n", l);
    return 0;
}
