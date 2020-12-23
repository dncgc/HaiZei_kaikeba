/*************************************************************************
	> File Name: 443.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sun Oct  4 16:07:56 2020
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

void make_label(int *tree, int start, int end) {
    for (int i = start; i <= end; ++i) {
        if (tree[i]) continue;
        tree[i] = 1;
    }
}

int main() {
    int l, m, start, end;
    scanf("%d%d", &l, &m);
    int *tree = (int *)calloc(l + 1, sizeof(int));
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &start, &end);
        make_label(tree, start, end);
    }
    int count = 0;
    for (int i = 0; i <= l; ++i) {
        if (tree[i]) continue;
        ++count;
    }
    printf("%d\n", count);
    return 0;
}
