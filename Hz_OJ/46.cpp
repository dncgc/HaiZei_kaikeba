/*************************************************************************
	> File Name: 46.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 03 Feb 2021 06:28:22 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;
#define MAX_N 500000

char str[MAX_N + 5];
int dp[MAX_N + 5];
vector<int> mark[MAX_N + 5];

/*
int is_palindrome(int l, int r) {
    while (l < r) {
        if (str[l++] != str[r--]) return 0;
    }
    return 1;
}
*/

void init_mark(int l, int r) {
    while(str[l] == str[r]) {
        mark[r].push_back(l);
        l--, r++;
        if (l < 1 || !str[r]) return ;
    }
    return ;
}

int main() {
    scanf("%s", str + 1);
    for (int i = 1; str[i]; i++) {
        init_mark(i, i);
        if (str[i + 1]) init_mark(i, i + 1);
        dp[i] = i;
        for (int j = 0; j < mark[i].size(); j++) {
            dp[i] = min(dp[i], dp[mark[i][j] - 1] + 1);
        }
    }
    printf("%d\n", dp[strlen(str + 1)] - 1);
    return 0;
}
