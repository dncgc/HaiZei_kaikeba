/*************************************************************************
	> File Name: exam.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon 07 Dec 2020 04:13:17 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define swap(a, b) {\
    __typeof(a) _a = a;\
    a = b; b = _a;\
}

typedef struct Node {
    int num, ind;
} Node;

int insert(Node *nodes, Node node, int n) {
    int ind = n;
    nodes[n] = node;
    for (int i = n; i > 0; i--) {
        if (nodes[i].num >= nodes[i - 1].num) break;
        swap(nodes[i], nodes[i - 1]);
        ind--;
    }
    return ind;
}

void output(Node *nodes, int n) {
    Node *temp = (Node *)malloc(sizeof(Node) * n);
    int ind = insert(temp, nodes[0], 0), ans1 = 0, ans2 = 0, element;
    for (int i = 1; i < n; i++) {
        ind = insert(temp, nodes[i], i);
        ans1 = (ind == 0 ? -1 : abs(temp[ind].num - temp[ind - 1].num));
        ans2 = (ind == i ? -1 : abs(temp[ind].num - temp[ind + 1].num));
        if (ans1 < 0) {
            ans1 = ans2;
            element = temp[ind + 1].num;
        } else if (ans2 < 0) {
            element = temp[ind - 1].num;
        } else if (ans1 == ans2){
            element = (temp[ind - 1].ind < temp[ind + 1].ind ? temp[ind - 1].num : temp[ind + 1].num);
        } else {
            ans1 = (ans1 < ans2 ? ans1 : ans2);
            element = (ans1 < ans2 ? temp[ind - 1].num : temp[ind + 1].num);
        }
        printf("%d %d\n", ans1, element);
    }
    free(temp);
    return ;
}

int main() {
    int n;
    scanf("%d", &n);
    Node nodes[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nodes[i].num);
        nodes[i].ind = i;
    }
    output(nodes, n);
    return 0;
}
