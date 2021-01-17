/*************************************************************************
	> File Name: my_RBtree.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sun 17 Jan 2021 08:03:57 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int key, color;
    struct Node *lchild, *rchild;
} Node;

Node __NIL;
#define NIL (&__NIL)
__attribute__((constructor))
void init_NIL() {
    NIL->key = 0;
    NIL->color = 1;
    NIL->lchild = NIL->rchild = NIL;
    return ;
}

Node *getNewNode(int val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->key = val;
    p->color = 0;
    p->lchild = p->rchild = NIL;
    return p;
}

int has_red_child(Node *root) {
    return root->lchild->color == 0 || root->rchild->color == 0;
}

Node *right_roate(Node *root) {
    Node *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    return temp;
}

Node *left_roate(Node *root) {
    Node *temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    return temp;
}

Node *insert_maintain(Node *root) {
    if (!has_red_child(root)) return root;
    if (root->lchild->color == 0 && root->rchild->color == 0 && 
        (has_red_child(root->lchild) || has_red_child(root->rchild))) {
        root->color = 0;
        root->lchild->color = root->rchild->color = 1;
    }
    int flag = 0;
    if (root->lchild->color == 0 && has_red_child(root->lchild)) flag = 1;
    if (root->rchild->color == 0 && has_red_child(root->rchild)) flag = 2;
    if (!flag) return root;
    if (flag == 1) {
        if (root->lchild->rchild->color == 0) {
            root->lchild = left_roate(root->lchild);
        }
        root = right_roate(root);
    } else {
        if (root->rchild->lchild->color == 0) {
            root->rchild = right_roate(root->rchild);
        }
        root = left_roate(root);
    }
    root->color = 0;
    root->lchild->color = root->rchild->color = 1;
    return root;
}

Node *__insert(Node *root, int val) {
    if (root == NIL) return getNewNode(val);
    if (root->key == val) return root;
    if (val < root->key) {
        root->lchild = __insert(root->lchild, val);
    } else {
        root->rchild = __insert(root->rchild, val);
    }
    return insert_maintain(root);
}

Node *insert(Node *root, int val) {
    root = __insert(root, val);
    root->color = 1;
    return root;
}

Node *predecessor(Node *root) {
    Node *temp = root->lchild;
    while(temp->rchild != NIL) temp = temp->rchild;
    return temp;
}

Node *erase_maintain(Node *root) {
    if (root->lchild->color != 2 && root->rchild->color != 2) return root;
    if (has_red_child(root)) {
        root->color = 0;
        if (root->lchild->color == 0) {
            root = right_roate(root);
            //root->color = 1;
            root->rchild = erase_maintain(root->rchild);
        } else {
            root = left_roate(root);
            //root->color = 1;
            root->lchild = erase_maintain(root->lchild);
        }
        root->color = 1;
        return root;
    }
    if ((root->lchild->color == 2 && !has_red_child(root->rchild)) ||
        (root->rchild->color == 2 && !has_red_child(root->lchild))) {
        root->color += 1;
        root->lchild->color -= 1;
        root->rchild->color -= 1;
        return root;
    }
    if (root->lchild->color == 2) {
        if (root->rchild->rchild->color != 0) {
            root->rchild->color = 0;
            root->rchild = right_roate(root->rchild);
            root->rchild->color = 1;
        }
        root->lchild->color = 1;
        root = left_roate(root);
        root->color = root->lchild->color;
    } else {
        if (root->lchild->lchild->color != 0) {
            root->lchild->color = 0;
            root->lchild = left_roate(root->lchild);
            root->lchild->color = 1;
        }
        root->rchild->color = 1;
        root = right_roate(root);
        root->color = root->rchild->color;
    }
    root->lchild->color = root->rchild->color = 1;
    return root;
}

Node *__erase(Node *root, int val) {
    if (root == NIL) return NIL;
    if (val < root->key) {
        root->lchild = __erase(root->lchild, val);
    } else if (val > root->key) {
        root->rchild = __erase(root->rchild, val);
    } else {
        if (root->lchild == NIL || root->rchild == NIL) {
            Node *temp = (root->lchild != NIL ? root->lchild : root->rchild);
            temp->color += root->color;
            free(root);
            return temp;
        } else {
            Node *temp = predecessor(root);
            root->key = temp->key;
            root->lchild = __erase(root->lchild, temp->key);
        } 
    }
    return erase_maintain(root);
}

Node *erase(Node *root, int val) {
    root = __erase(root, val);
    root->color = 1;
    return root;
}

void clear(Node *root) {
    if (root == NIL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

void print(Node *root) {
    printf("%d | [%d], [%d], [%d]\n", root->color, root->key, root->lchild->key, root->rchild->key);
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
            case 1: root = insert(root, val); break;
            case 0: root = erase(root, val); break;
        }
        output(root);
        printf("--------------\n");
    }
    clear(root);
    return 0;
}
