/*************************************************************************
	> File Name: 根据三元组建立二叉链表.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon 25 Jan 2021 08:15:34 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

typedef struct Node {
    char ch;
    struct Node *lchild, *rchild;
} Node;

Node *arr[26];

Node *getNewNode(char ch) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->ch = ch;
    p->lchild = p->rchild = NULL;
    return p;
}

char str[10];

void output(Node *root) {
    if (root == NULL) return ;
    printf("%c", root->ch);
    if (root->lchild == NULL && root->rchild == NULL) return ;
    printf("(");
    output(root->lchild);
    if (root->rchild) printf(",");
    output(root->rchild);
    printf(")");
    return ;
}

int main() {
    Node *root = NULL, *p;
    while (~scanf("%s", str)) {
        if (str[0] == '^' && str[1] == '^') break;
        p = getNewNode(str[1]);
        arr[str[1] - 'A'] = p;
        if (str[0] == '^') {
            root = p;
            continue;
        }
        switch (str[2]) {
            case 'L': arr[str[0] - 'A']->lchild = p; break;
            case 'R': arr[str[0] - 'A']->rchild = p; break;
        }
    }
    output(root);
    printf("\n");
    return 0;
}
