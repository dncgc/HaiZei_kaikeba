/*************************************************************************
	> File Name: 637.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 04 Mar 2021 08:30:45 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;

struct edge {
    int e, next;
};

int n, m, head[30], in_degree[30], ans_cnt;
edge edg[5005];
char ans[30];

void add_edg(char a, char b, int edg_cnt) {
    int s = a - 'A' + 1, e = b - 'A' + 1;
    edg[edg_cnt].e = e;
    edg[edg_cnt].next = head[s];
    head[s] = edg_cnt;
    in_degree[e]++;
}

//t==1 有答案； t == 2 有环； t == 0 无答案
int func() {
    ans_cnt = 0;
    int tin[30];
    queue<int> que;
    for (int i = 1; i <= n; i++) {
        tin[i] = in_degree[i];
        if (tin[i] == 0) {
            que.push(i);
        }
    }
    //f1表示起点的数量，若不为1，无答案
    //f2总入队标记，==1，无答案
    //f3成环标记，==1，成环
    //f4每一轮入队标记，>1, f2 = 1
    int f1 = que.size(), f2 = 0, f3 = 0;
    while (!que.empty()) {
        int t = que.front(), f4 = 0;
        que.pop();
        ans[ans_cnt++] = t + 'A' - 1;
        for (int i = head[t]; i != -1; i = edg[i].next) {
            int e = edg[i].e;
            tin[e]--;
            if (tin[e] == 0) {
                que.push(e);
                f4++;
            }
        }
        if (f4 > 1) {
            f2 = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (tin[i] != 0) {
            f3 = 1;
            break;
        }
    }
    if (f3 == 1) return 2;
    if (f1 > 1 || f2 == 1) return 0;
    return 1;
}

int main() {
    memset(head, -1, sizeof(head));
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        char a, b;
        cin >> a >> b >> b;
        add_edg(a, b, i);
        int t = func();
        if (t == 1) {
            printf("Sorted sequence determined after %d relations: %s.", i, ans);
            return 0;
        } else if (t == 2) {
            printf("Inconsistency found after %d relations.\n", i);
            return 0;
        }
    }
    printf("Sorted sequence cannot be determined.\n");
    return 0;
}
