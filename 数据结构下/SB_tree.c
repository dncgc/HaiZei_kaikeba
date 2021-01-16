/*************************************************************************
    > File Name: SB_tree.c
    > Author: Cui Guochong
    > Mail: gc_cui@seu.edu.cn
    > Created Time: Thu 07 Jan 2021 10:52:26 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define L(n) (n->lchild)
#define R(n) (n->rchild)
#define S(n) (n->size)

typedef struct Node {
    int key, size;
    struct Node *lchild, *rchild;
} Node;

Node __NIL;
#define NIL (&__NIL)
__attribute__((constructor))
void init_NIL() {
    NIL->key = 0, NIL->size = 0;
    NIL->lchild = NIL->rchild = NIL;
    return ;
}

Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = val;
    p->size = 1;
    p->lchild = p->rchild = NIL;
    return p;
}

Node *precessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild != NIL) temp = temp->rchild;
    return temp;
}

void update_size(Node *root) {
    root->size = root->lchild->size + root->rchild->size + 1;
}

Node *roate_left(Node *root) {
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    update_size(root);
    update_size(temp);
    return temp;
}

Node *roate_right(Node *root) {
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    update_size(root);
    update_size(temp);
    return temp;
}

Node *maintain(Node *root) {
    if (S(R(root)) >= S(L(L(root))) && 
        S(R(root)) >= S(R(L(root))) &&
        S(L(root)) >= S(R(R(root))) && 
        S(L(root)) >= S(L(R(root)))) {
        return root;
    }
    if (S(R(root)) < S(L(root))) {
        if (S(R(root)) < S(R(L(root)))) {
            root->lchild = roate_left(root->lchild);
        }
        root = roate_right(root);
    } else {
        if (S(L(root)) < S(L(R(root)))) {
            root->rchild = roate_right(root->rchild);
        }
        root = roate_left(root);
    }
    return root;
}

Node *insert(Node *root, int val) {
    if (root == NIL) {
        return getNewNode(val);
    }
    if (val == root->key) return root;
    if (val < root->key) root->lchild = insert(root->lchild, val);
    else root->rchild = insert(root->rchild, val);
    update_size(root);
    return maintain(root);
}

Node *erase(Node *root, int val) {
    if (root == NIL) return NIL;
    if (val < root->key) {
        root->lchild = erase(root->lchild, val);
    } else if (val > root->key) {
        root->rchild = erase(root->rchild, val);
    } else {
        if (root->lchild == NIL || root->rchild == NIL) {
            Node *temp = root->lchild == NIL ? root->rchild : root->lchild;
            free(root);
            return temp;
        } else {
            Node *temp = precessor(root);
            root->key = temp->key;
            root->lchild = erase(root->lchild, temp->key);
        }
    }
    update_size(root);
    return maintain(root);
}

void print(Node *root) {
    printf("%d[%d], %d, %d\n", root->key, root->size,
        root->lchild->key, root->rchild->key);
    return ;
}

void output(Node *root) {
    if (root == NIL) return;
    print(root);
    output(root->lchild);
    output(root->rchild);
    return ; 
}

void clear(Node *root) {
    if (root == NIL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

int main() {
    int op, val;
    Node *root = NIL;
    while (~scanf("%d%d", &op, &val)) {
        switch (op) {
            case 1: root = insert(root, val); break;
            case 0: root = erase(root, val); break;
        }
        output(root);
        printf("--------------\n");
    }
    clear(root);
    return 0;
}
