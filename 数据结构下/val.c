/*************************************************************************
	> File Name: val.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 19 Dec 2020 03:47:42 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define L(n) (n->lchild)
#define R(n) (n->rchild)
#define H(n) (n->h)

typedef struct Node {
    int key, h;
    struct Node *lchild, *rchild;
} Node;

Node __NIL;
#define NIL (&__NIL)
__attribute__((constructor))
void init_NIL() {
    NIL->key = 0, NIL->h = 0;
    NIL->lchild = NIL->rchild = NIL;
    return ;
}

Node *getNewNode(int key) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = key;
    p->h = 1;
    p->lchild = p->rchild = NIL;
    return p;
}

void update_height(Node *root) {
    root->h = H(L(root)) > H(R(root)) ? H(L(root)) + 1 : H(R(root)) + 1;
    return ;
}

Node *left_rotate(Node *root) {
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    update_height(root);
    update_height(temp);
    return temp;
}

Node *right_rotate(Node *root) {
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    update_height(root);
    update_height(temp);
    return temp;

}
Node *maintain(Node *root) {
    if (abs(H(L(root)) - H(R(root))) <= 1) return root;
    if (root->lchild->h > root->rchild->h) {
        if (root->lchild->lchild->h < root->lchild->rchild->h) {
            root->lchild = left_rotate(root->lchild);
        }
        root = right_rotate(root);
    } else {
        if (root->rchild->rchild->h < root->rchild->lchild->h) {
            root->rchild = right_rotate(root->rchild);
        }
        root = left_rotate(root);
    }
}

Node *insert(Node *root, int key) {
    if (root == NIL) return getNewNode(key);
    if (root->key == key) return root;
    if (key < root->key) {
        root->lchild = insert(root->lchild, key);
    } else {
        root->rchild = insert(root->rchild, key);
    }
    update_height(root);
    return maintain(root);
}

Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while (temp->rchild != NIL) temp = temp->rchild;
    return temp;
}

Node *erase(Node *root, int key) {
    if (root == NIL) return NIL;
    if (key < root->key) {
        root->lchild = erase(root->lchild, key);
    } else if (key > root->key) {
        root->rchild = erase(root->rchild, key);
    } else {
        if (root->lchild == NIL || root->rchild == NIL) {
            Node *temp = root->lchild != NIL ? root->lchild : root->rchild;
            free(root);
            return temp;
        } else {
            Node *temp = predecessor(root);
            root->key = temp->key;
            root->lchild = erase(root->lchild, temp->key);
        }
    }
    update_height(root);
    return maintain(root);
}

void clear(Node *root) {
    if (root == NIL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void print(Node *root) {
    printf("(%d[%d], %d, %d)\n",
        root->key, root->h,
        root->lchild->key,
        root->rchild->key
    );
    return ;
}

void output(Node *root) {
    if (root == NIL) return ;
    print(root);
    output(root->lchild);
    output(root->rchild);
    return ;
}

int main() { 
    int op, val;
    Node *root = NIL;
    while (~scanf("%d%d", &op, &val)) {
        switch (op) {
            case 0: root = erase(root, val); break;
            case 1: root = insert(root, val); break;
        }
        output(root);
        printf("----------\n");
    }
    return 0;
}
