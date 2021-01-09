/*************************************************************************
	> File Name: HZOJ44_v1.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 09 Jan 2021 09:18:44 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;
#define MAX_N 1000000
int dp[MAX_N + 5];
int len[MAX_N + 5];

int binary_search(int *arr, int n, int x) {
    int head = 0, tail = n, mid;
    while (head < tail) {
        mid = (head + tail) >> 1;
        if (arr[mid] < x) head = mid + 1;
        else tail = mid;
    }
    return head;
}

int main() {
    int n, ans = 0, a;
    cin >> n;
    memset(len, 0x3f, sizeof(len));
    len[0] = 0;
    for (int i = 1; i <=n; i++) {
        cin >> a;
        dp[i] = binary_search(len, ans + 1, a);
        len[dp[i]] = a;
        ans = max(dp[i], ans);
    }
    cout << ans << endl;
    return 0;
}
