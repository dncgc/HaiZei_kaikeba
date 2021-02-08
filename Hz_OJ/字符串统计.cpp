/*************************************************************************
	> File Name: 字符串统计.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon 08 Feb 2021 12:53:22 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

#define BASE 26
#define MAX_N 20000

struct Node {
    int flag, *cnt;
    int next[26], fail;
} tree[MAX_N + 5];
int que[MAX_N + 5], head, tail;
int *ans[MAX_N + 5];
int root = 1, cnt = 2;
char str[100005];
int n;

int getNewNode() { return cnt++; }
int *insert(const char *str) {
    int p = root;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - 'a';
        if (tree[p].next[ind] == 0) tree[p].next[ind] = getNewNode();
        p = tree[p].next[ind];
    }
    tree[p].flag = 1;
    if (tree[p].cnt == NULL) {
        tree[p].cnt = (int *)malloc(sizeof(int));
        tree[p].cnt[0] = 0;
    }
    return tree[p].cnt;
}

void build() {
    head = tail = 0;
    tree[root].fail = 0;
    for (int i = 0; i < BASE; i++) {
        if (tree[root].next[i] == 0) {
            tree[root].next[i] = root;
            continue;
        }
        tree[tree[root].next[i]].fail = root;
        que[tail++] = tree[root].next[i];
    }
    while (head < tail) {
        int p = que[head++];
        for (int i = 0; i < BASE; i++) {
            int c = tree[p].next[i], k = tree[p].fail;
            if (c == 0) {
                tree[p].next[i] = tree[k].next[i];
                continue;
            }
            k = tree[k].next[i];
            tree[c].fail = k;
            que[tail++] = c;
        }
    }
    return ;
}

void match(const char *str) {
    int p = root;
    for (int i = 0; str[i]; i++) {
        int ind = str[i] - 'a', q;
        p = tree[p].next[ind];
        q = p;
        while(q) {
            if (tree[q].flag) {
                (*tree[q].cnt) += 1;
            }
            q = tree[q].fail;
        }
    }
    return ;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%s", str);
        ans[i] = insert(str);
    }
    scanf("%s", str);
    build();
    match(str);
    for (int i = 0; i < n; i++) {
        printf("%d: %d\n", i, *ans[i]);
    }
    return 0;
}
