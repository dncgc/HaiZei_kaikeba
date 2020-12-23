/*************************************************************************
	> File Name: 218.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 30 Sep 2020 02:42:53 PM CST
 ************************************************************************/

#include <stdio.h>

int cnt[301];

int location(int h, int *count) {
    int sum = 0;
    for (int i = 0; i < h; ++i) sum += count[i];
    return sum + (++cnt[h]);
}

int main() {
    int n;
    scanf("%d", &n);
    int height[n + 1], sort[n + 1];
    int count[301] = {0};
    for (int i = 1; i <= n; ++i) {
        scanf("%d", height + i);
        ++count[height[i]];
    }
    for (int i = 1; i <= n; ++i) {
        sort[location(height[i], count)] = i;
    }
    for (int i = 1; i <= n; ++i) {
        i == 1 || printf(" ");
        printf("%d", sort[i]);
    }
    printf("\n");
    return 0;
}
