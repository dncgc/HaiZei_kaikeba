/*************************************************************************
	> File Name: 9.binary_tree.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 01 Apr 2021 08:33:56 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

typedef struct Node {
    int key;
    struct Node *lchild, *rchild;
} Node;

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->lchild = p->rchild = NULL;
    return p;
}

Node *random_insert(Node *root, int key) {
    if (root == NULL) return getNewNode(key);
    if (rand() % 2) {
        root->lchild = random_insert(root->lchild, key);
    } else {
        root->rchild = random_insert(root->rchild, key);
    }
    return root;
}

void pre_order(Node *root) {
    if (root == NULL) return ;
    printf("%d ", root->key);
    pre_order(root->lchild);
    pre_order(root->rchild);
    return ;
}

void in_order(Node *root) {
    if (root == NULL) return ;
    pre_order(root->lchild);
    printf("%d ", root->key);
    pre_order(root->rchild);
    return ;
}

int main(int argc, char *argv[]) {
    srand(time(0));
    if (argc != 2) return 0;
    int MAX_N = atoi(argv[1]);
    Node *root = NULL;
    for (int i = 1; i <= MAX_N; i++) {
        root = random_insert(root, i);
    }
    pre_order(root); printf("\n");
    in_order(root); printf("\n");
    return 0;
}
