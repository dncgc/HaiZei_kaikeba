/*************************************************************************
	> File Name: my_twoside_Linklist.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 24 Nov 2020 02:33:56 PM CST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node *front, *next;
} Node;

typedef struct LinkList {
    Node head, tail;
    int length;
} LinkList;

Node *getnewnode(int);
LinkList *getnewlist();
void clear_node(Node*);
void clear_list(LinkList *);
int insert(LinkList*, int, int);
int delete_node(LinkList*, int);
void front_output(LinkList*);
void post_output(LinkList*);

int main() {
    srand(time(0));
    #define max_op 20
    LinkList *l = getnewlist();
    for (int i = 0; i < max_op; ++i) {
        int val = rand() % 100;
        int ind = rand() % (l->length + 3) - 1;
        int op = rand() % 4;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                printf("insert %d at %d int the list = %d\n", val, ind, insert(l, ind, val));
            } break;
            case 3: {
                printf("remove iterm at %d int the list = %d\n", ind, delete_node(l, ind));
            } break;
        }
        front_output(l);
        post_output(l);
        printf("\n");
    }
    #undef max_op
    clear_list(l);
    return 0;
}

Node *getnewnode(int val) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = val;
    n->front = n->next = NULL;
    return n;
}

LinkList *getnewlist() {
    LinkList *l = (LinkList *)malloc(sizeof(LinkList));
    l->head.next = &(l->tail);
    l->tail.front = &(l->head);
    l->head.front = l->tail.next = NULL;
    l->length = 0;
    return l;
}

int insert(LinkList *l, int ind, int val) {
    if (!l) return 0;
    if (ind < 0 || ind > l->length) return 0;
    Node *p = &(l->head), *q;
    while (ind--) p = p->next;
    q = getnewnode(val);
    q->next = p->next;
    p->next = q;
    q->next->front = q;
    q->front =  p;
    l->length += 1;
    return 1;
}

int delete_node(LinkList *l, int ind){
    if (!l) return 0;
    if (ind < 0 || ind >= l->length) return 0;
    Node *p = &(l->head), *q;
    while (ind--) p = p->next;
    q = p->next;
    p->next = q->next;
    q->next->front = q->front;
    clear_node(q);
    l->length -= 1;
    return 1;
}

void front_output(LinkList *l) {
    printf("list(%d) front output: ", l->length);
    Node *p = l->head.next;
    while (p != &(l->tail)) {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

void post_output(LinkList *l) {
    printf("List(%d) post output: ", l->length);
    Node *p = l->tail.front;
    while (p != &(l->head)) {
        printf("%d->", p->data);
        p = p->front;
    }
    printf("NULL\n");
}

void clear_node(Node *n) {
    if (!n) return ;
    free(n);
    return ;
}

void clear_list(LinkList *l) {
    if (!l) return ;
    Node *p = l->head.next, *q;
    while (p != &(l->tail)) {
        q = p->next;
        clear_node(p);
        p = q;
    }
    free(l);
    return ;
}
