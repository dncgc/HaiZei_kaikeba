/*************************************************************************
	> File Name: my_haffman.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon 18 Jan 2021 10:18:40 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAX_N 100

#define swap(a, b) {\
    __typeof(a) _a = a;\
    a = b; b = _a;\
}

typedef struct Node {
    char ch;
    double p;
    struct Node *lchild, *rchild;
} Node;

typedef struct Priority_queue {
    Node **arr;
    int size;
} pq;

pq *init_pq() {
    pq *q = (pq *)malloc(sizeof(pq));
    q->arr = (Node **)malloc(sizeof(Node *) * MAX_N);
    q->size = 0;
    return q;
}

void push(pq *p, Node *a) {
    p->arr[p->size++] = a;
    int ch = p->size - 1, fa = (ch - 1) >> 1;
    while(ch) {
        if (p->arr[ch]->p >= p->arr[fa]->p) break;
        swap(p->arr[ch], p->arr[fa]);
        ch = fa;
        fa >>= 1;
    }
    return ;
}

void update(pq *p, int ind, int n) {
    int l = ind << 1 | 1, r = l + 1, min = ind;
    if (l <= n) {
        min = (p->arr[l]->p < p->arr[min]->p ? l : min);
        if (r <= n) min = (p->arr[r]->p < p->arr[min]->p ? r : min);
        if (min == ind) return ;
        swap(p->arr[min], p->arr[ind]);
        update(p, min, n);
    }
    return ;
}

void pop(pq *p) {
    swap(p->arr[p->size - 1], p->arr[0]);
    p->size -= 1;
    update(p, 0, p->size - 1);
    return ;
}

void clear_pq(pq *p) {
    if (p == NULL) return ;
    free(p->arr);
    free(p);
    return ;
}

Node *getNewNode(char ch, double pe) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->ch = ch;
    p->p = pe;
    p->lchild = p->rchild = NULL;
    return p;
}

Node *combineNode(Node *a, Node *b) {
    Node *temp = getNewNode(0, a->p + b->p);
    temp->lchild = a;
    temp->rchild = b;
    return temp;
}
/*
void put_min(Node **arr, int n) {
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i]->p < arr[n]->p) swap(arr[i], arr[n]);
    }
}

Node *getHaffmantree(Node **arr, int n) {
    for (int i = 1; i < n; i++) {
        put_min(arr, n - i);
        put_min(arr, n - i - 1);
        arr[n - i - 1] = combineNode(arr[n - i], arr[n - i - 1]);
    }
    return arr[0];
}
*/

Node *getHaffmantree(pq *p, int n) {
    for (int i = 1; i < n; i++) {
        Node *a = p->arr[0];
        pop(p);
        Node *b = p->arr[0];
        pop(p);
        push(p, combineNode(a, b));
    }
    return p->arr[0];
}

void __output_code(Node *root, char *str, int k) {
    str[k] = 0;
    if (root->lchild == NULL && root->rchild == NULL) {
        printf("%c : %s\n", root->ch, str);
        return ;
    }
    str[k] = '0';
    __output_code(root->lchild, str, k + 1);
    str[k] = '1';
    __output_code(root->rchild, str, k + 1);
    return ;
}

void output_code(Node *root) {
    char str[100];
    __output_code(root, str, 0);
    return ;
}

void clear(Node *root) {
    if (root == NULL) return ;
    clear(root->lchild);
    clear(root->rchild);
    free(root);
    return ;
}

int main() {
    int n;
    scanf("%d", &n);
    //Node **arr = (Node **)malloc(sizeof(Node *) * n);
    pq *que = init_pq();
    for (int i = 0; i < n; i++) {
        char ch[10];
        double p;
        scanf("%s%lf", ch, &p);
        push(que, getNewNode(ch[0], p));
        //arr[i] = getNewNode(ch[0], p);
    }
    //Node *root = getHaffmantree(arr, n);
    Node *root = getHaffmantree(que, n);
    output_code(root);
    clear(root);
    return 0;
}
