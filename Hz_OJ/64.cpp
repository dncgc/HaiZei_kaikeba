/*************************************************************************
	> File Name: 64.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon 08 Feb 2021 09:26:44 AM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct Node {
    int key, flag;
    Node *lchild, *rchild;
};

Node __NIL;
#define NIL (&__NIL)
__attribute__((constructor))
void init_NIL() {
    NIL->key = 0;
    NIL->flag = 1;
    NIL->lchild = NIL->rchild = NIL;
    return ;
}

Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = val;
    p->flag = 0;
    p->lchild = p->rchild = NIL;
    return p;
}

Node *left_roate(Node *root) {
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    return temp;
}

Node *right_roate(Node *root) {
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    return temp;
}

bool has_red_child(Node *root) {
    return root->lchild->flag == 0 || root->rchild->flag == 0;
}

void red_up(Node *root) {
    root->flag = 0;
    root->lchild->flag = root->rchild->flag = 1;
    return ;
}

Node *insert_maintain(Node *root) {
    if (!has_red_child(root)) return root;
    int flag = 0;
    if (root->lchild->flag == 0 && has_red_child(root->lchild)) flag = 1;
    if (root->rchild->flag == 0 && has_red_child(root->rchild)) flag = 2;
    if (flag == 0) return root;
    if (flag == 1) {
        if (root->rchild->flag == 0) {
            red_up(root);
            return root;
        }
        if (root->lchild->rchild->flag == 0) {
            root->lchild = left_roate(root->lchild);
        }
        root = right_roate(root);
    } else {
        if (root->lchild->flag == 0) {
            red_up(root);
            return root;
        }
        if (root->rchild->lchild->flag == 0) {
            root->rchild = right_roate(root->rchild);
        }
        root = left_roate(root);
    }
    red_up(root);
    return root;
}

Node *__insert(Node *root, int val) {
    if (root == NIL) return getNewNode(val);
    if (val > root->key) root->rchild = __insert(root->rchild, val);
    else if (val < root->key) root->lchild = __insert(root->lchild, val);
    else return root;
    return insert_maintain(root);
}

Node *insert(Node *root, int val) {
    root = __insert(root, val);
    root->flag = 1;
    return root;
}

Node *predecessor(Node *root) {
    Node *p = root->lchild;
    while (p->rchild != NIL) p = p->rchild;
    return p;
}

Node *erase_maintain(Node *root) {
    if (root->lchild->flag != 2 && root->rchild->flag != 2) return root;
    if (has_red_child(root)) {
        root->flag = 0;
        if (root->lchild->flag == 0) {
            root = right_roate(root);
            root->rchild = erase_maintain(root->rchild);
        } else {
            root = left_roate(root);
            root->lchild = erase_maintain(root->lchild);
        }
        root->flag = 1;
        return root;
    }
    if ((root->lchild->flag == 1 && !has_red_child(root->lchild)) ||
        root->rchild->flag == 1 && !has_red_child(root->rchild)) {
            root->flag += 1;
            root->lchild->flag -= 1;
            root->rchild->flag -= 1;
            return root;
        }
    if (root->lchild->flag == 2) {
        if (root->rchild->rchild->flag != 0) {
            root->rchild->flag = 0;
            root->rchild = right_roate(root->rchild);
            root->rchild->flag = 1;
        }
        root->lchild->flag = 1;
        root = left_roate(root);
        root->flag = root->lchild->flag;
    } else {
        if (root->lchild->lchild->flag != 0) {
            root->lchild->flag = 0;
            root->lchild = left_roate(root->lchild);
            root->lchild->flag = 1;
        }
        root->rchild->flag = 1;
        root = right_roate(root);
        root->flag = root->rchild->flag;
    }
    root->lchild->flag = root->rchild->flag = 1;
    return root;
}

Node *__erase(Node *root, int val) {
    if (root == NIL) return root;
    if (val > root->key) {
        root->rchild = __erase(root->rchild, val);
    } else if (val < root->key) {
        root->lchild = __erase(root->lchild, val);
    } else {
        if (root->lchild == NIL || root->rchild == NIL) {
            Node *temp = (root->lchild == NIL ? root->rchild : root->lchild);
            temp->flag += root->flag;
            free(root);
            return temp;
        }
        Node *temp = predecessor(root);
        root->key = temp->key;
        root->lchild = __erase(root->lchild, temp->key);
    }
    return erase_maintain(root);
}

Node *erase(Node *root, int val) {
    root = __erase(root, val);
    root->flag = 1;
    return root;
}

void clear(Node *root) {
    if (root == NIL) return;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void output(Node *root) {
    if (root == NIL) return ;
    output(root->lchild);
    printf("%d %d %d %d\n", root->key, root->flag, root->lchild->key, root->rchild->key);
    output(root->rchild);
    return ;
}

int main() {
    int x, y;
    Node *root = NIL;
    while (~scanf("%d%d", &x, &y)) {
        switch(x) {
            case 1: {
                root = insert(root, y);
            } break;
            case 2: {
                root = erase(root, y);
            } break;
            case 3: {
                output(root);
            } break;
        }
    }
    return 0;
}
