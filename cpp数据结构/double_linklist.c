/*************************************************************************
	> File Name: double_linklist.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 05 Dec 2020 04:13:40 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next, *front;
} Node;

typedef struct LinkList {
    Node *head;
} LinkList;

Node *init_node(int n) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = n;
    node->next = node->front = NULL;
    return node;
}

LinkList *init_list() {
    LinkList *l = (LinkList *)malloc(sizeof(LinkList));
    l->head = NULL;
    return l;
}

void insert(LinkList *l, int num) {
    Node *n = init_node(num);
    if (!l->head) {
        l->head = n;
        l->head->next = l->head;
        l->head->front = l->head;
    }
    else {
        n->next = l->head->next;
        l->head->next = n;
        n->next->front = n;
        n->front = l->head;
        l->head = n;
    }
    return ;
}

void output(LinkList *l, int num) {
    while(l->head->data != num) l->head = l->head->next;
    Node *p = l->head;
    do {
        p == l->head || printf(" ");
        printf("%d", p->data);
        p = p->front;
    } while(p != l->head);
    printf("\n");
    return ;
}

void clear_node(Node *n) {
    if (!n) return ;
    free(n);
    return ;
}

void clear_list(LinkList *l) {
    if (!l) return ;
    Node *p = l->head, *delete_node = p->next;
    p->next = NULL;
    while (delete_node) {
        p = delete_node->next;
        clear_node(delete_node);
        delete_node = p;
    }
    free(l);
    return ;
}

int main() {
    int n;
    scanf("%d", &n);
    int num;
    LinkList *l = init_list();
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        insert(l, num);
    }
    scanf("%d", &n);
    output(l, n);
    clear_list(l);
    return 0;
}
