/*************************************************************************
	> File Name: 2.list.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 24 Nov 2020 01:49:21 PM CST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLOR(a, b) "\033[" #b "m" a "\033[0m" 
#define GREEN(a) COLOR(a, 32)

typedef struct ListNode {
    int data;
    struct ListNode *next;
} ListNode;

typedef struct List {
    ListNode head;
    int length;
} List;

ListNode *getNewNode(int);
List *getLinkList();
void clear_node(ListNode *);
void clear(List *);
int insert(List *, int, int);
int erase(List *, int);
void output(List *);
void reverse(List *l);

int main() {
    srand(time(0));
    #define max_op 20
    List *l = getLinkList();
    for (int i = 0; i < max_op; i++) {
        int val = rand() % 100;
        int ind = rand() % (l->length + 3) - 1;
        int op = rand() % 4;
        switch (op) {
            case 0:
            case 1: {
                printf("insert %d at %d to list = %d\n", val, ind, insert(l, ind, val));
            } break;
            case 2: {
                printf(GREEN("reverse the List!\n"));
                reverse(l);
            } break;
            case 3: {
                printf("erase iterm at %d from List = %d\n", ind, erase(l, ind));
            } break;
        }
        output(l);
        printf("\n");
    }
    #undef max_op
    clear(l);
    return 0;
}

ListNode *getNewNode(int val) {
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = val;
    p->next = NULL;
    return p;
}

List *getLinkList() {
    List *l = (List *)malloc(sizeof(List));
    l->head.next = NULL;
    l->length = 0;
    return l;
}

int insert(List *l, int ind, int val) {
    if (l == NULL) return 0;
    if (ind < 0 || ind > l->length) return 0;
    ListNode  *p = &(l->head), *node = getNewNode(val);
    while (ind--) p = p->next;
    node->next = p->next;
    p->next = node;
    l->length += 1;
    return 1;
}

int erase(List *l, int ind) {
    if (l == NULL) return 0;
    if (ind < 0 || ind >= l->length) return 0;
    ListNode *p = &(l->head), *q;
    while (ind--) p = p->next;
    q = p->next;
    p->next = q->next;
    free(q);
    l->length -= 1;
    return 1;
}

void reverse(List *l) {
    ListNode *p = l->head.next, *q;
    l->head.next = NULL;
    while (p) {
        q = p->next;
        p->next = l->head.next;
        l->head.next = p;
        p = q;
    }
    return ;
}

void output(List *l) {
    if (!l) return ;
    printf("List(%d) = [", l->length);
    for (ListNode *p = l->head.next; p; p = p->next) {
        printf("%d->", p->data);
    }
    printf("NULL]\n");
    return ;
}

void clear_node(ListNode *node) {
    if (node == NULL) return ;
    free(node);
    return ;
}

void clear(List *l) {
    if (l == NULL) return ;
    ListNode *p = l->head.next, *q;
    while (p) {
        q = p->next;
        clear_node(p);
        p = q;
    }
    free(l);
    return ;
}
