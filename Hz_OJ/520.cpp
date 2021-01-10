/*************************************************************************
	> File Name: 520.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sun 10 Jan 2021 11:35:57 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
using namespace std;
#define MAX_A 1940500
#define MAX_N 2940500
long long s[MAX_N + 5];

int main() {
    int a;
    for (int i = 1; i <= MAX_N; i++) {
        s[i] += s[i - 1] + i;
    }
    scanf("%d", &a);
    for (int i = a; i <= MAX_A; i++) {
        for (int j = i + 1; j <= MAX_N; j++) {
            if (s[i - 1] == s[j] - s[i]) {
                printf("%d %d\n", i, j);
                return 0;
            }
            else if (s[i - 1] < s[j] - s[i]) break;
        }
    }
    return 0;
}
