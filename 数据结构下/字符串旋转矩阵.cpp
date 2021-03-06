/*************************************************************************
	> File Name: 字符串旋转矩阵.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 26 Jan 2021 02:05:46 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX_N 110000
char t[MAX_N + 5], s[MAX_N + 5];
int ind[MAX_N + 5], *ans[MAX_N + 5];

bool cmp(int i, int j) {
    if (t[i] - t[j]) return t[i] < t[j];
    return i < j;
}

void convert(char *t, char *s) {
    int n = 0;
    for (n = 0; t[n]; n++) ind[n] = n;
    sort(ind, ind + n, cmp);
    for (int i = 0, p = ind[0]; i < n; i++, p = ind[p]) {
        s[i] = t[p];
    }
    s[n] = 0;
    //printf("%s\n", s);
    return ;
}

struct Node {
    int flag, *ans;
    int next[26], fail;
} tree[2000005];
int que[2000005], head, tail;
int root = 1, cnt = 2;
inline int getNewNode() { return cnt++; }
int* insert(char *s) {
    int p = root;
    for (int i = 0; s[i]; i++) {
        int ind = s[i] - 'a';
        if (tree[p].next[ind] == 0) tree[p].next[ind] = getNewNode();
        p = tree[p].next[ind];
    }
    tree[p].flag = 1;
    if (tree[p].ans == NULL) {
        tree[p].ans = new int(0);
    }
    return tree[p].ans;
}

void build() {
    head = tail = 0;
    tree[root].fail = 0;
    for (int i = 0; i < 26; i++) {
        if (tree[root].next[i] == 0) {
            tree[root].next[i] = root;
            continue;
        }
        tree[tree[root].next[i]].fail = root;
        que[tail++] = tree[root].next[i];
    }
    while (head < tail) {
        int p = que[head++];
        for (int i = 0; i < 26; i++) {
            int c = tree[p].next[i], k = tree[p].fail;
            if (c == 0) {
                tree[p].next[i] = tree[k].next[i];
                continue;
            }
            tree[c].fail = tree[k].next[i];
            que[tail++] = c;
        }
    }
    return ;
}

void match(char *s) {
    for (int i = 0, p = tree[root].next[s[0] - 'a'], q, k; s[i]; i++, p = tree[p].next[s[i] - 'a']) {
        q = p;
        while (q) {
            if (tree[q].flag) {
                *tree[q].ans += 1;
            }
            k = q;
            q = tree[q].fail;
            tree[k].fail = 0;
        }
    }
    return ;
}

void init() {
    cnt = 2;
    memset(tree, 0, sizeof(tree));
    memset(ans, 0, sizeof(ans));
    return ;
}

int solve(char *t) {
    init();
    convert(t, s);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        ans[i] = insert(t);
    }
    build();
    match(s + 1);
    for (int i = 0; i < n; i++) {
        cout << (ans[i][0] ? "YES" : "NO") << endl;
    }

    return 0;
}

int main() {
    while (cin >> t) solve(t);
    return 0;
}
