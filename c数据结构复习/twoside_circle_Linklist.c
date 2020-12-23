/*************************************************************************
	> File Name: twoside_circle_Linklist.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 25 Nov 2020 04:29:53 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node *next, *front;
} Node;

typedef struct List {
    Node *head;
    int cnt;
} List;

Node *init_node(int);
List *init_list();
void clear_node(Node *);
void clear_list(List *);
int insert(List *, int, int);
int delete_node(List *, int);
void output();

int main() {
    srand(time(0));
    List *l = init_list();
    #define max_op 20
    for (int i = 0; i < max_op; ++i) {
        int val = rand() % 100;
        int ind = rand() % (l->cnt + 3) - 1;
        int op = rand() % 4;
        switch(op) {
            case 0:
            case 1:
            case 2: {
                printf("insert %d at %d in the list = %d\n", val, ind, insert(l, val, ind));
            } break;
            case 3: {
                printf("delete the number at %d in the list = %d\n", ind, delete_node(l, ind));
            } break;
        }
        output(l), printf("\n");
    }
    #undef max_op
    clear_list(l);
    return 0;
}

Node *init_node(int val) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = val;
    n->next = n->front = NULL;
    return n;
}

List *init_list() {
    List *l = (List *)malloc(sizeof(List));
    l->head = NULL;
    l->cnt = 0;
    return l;
}

int insert(List *l, int val, int ind) {
    if (!l) return 0;
    if (ind < 0 || ind > l->cnt) return 0;
    if (l->cnt == 0) {
        l->head = init_node(val);
        l->head->next = l->head;
        l->head->front = l->head;
    } else {
        Node *p = l->head, *q = init_node(val);
        int n = ind;
        while(n--) p = p->next;
        q->next = p->next;
        p->next = q;
        q->next->front = q;
        q->front = p;
        if (ind == l->cnt) l->head = q;
    }
    ++l->cnt;
    return 1;
}

int delete_node(List *l, int ind) {
    if (!l) return 0;
    if (ind < 0 || ind >= l->cnt) return 0;
    int n = ind;
    Node *p = l->head, *q;
    while (n--) p = p->next;
    q = p->next;
    p->next = q->next;
    q->next->front = p;
    clear_node(q);
    if (ind == l->cnt) l->head = p;
    --l->cnt;
    return 1;
}

void output(List *l) {
    Node *p = l->head;
    printf("double side circle List(%d) : front : ", l->cnt);
    for (int i = 0; i < (l->cnt << 1); ++i) {
        i && printf("->");
        printf("%d", p->next->data);
        p = p->next;
    }
    printf("\n");
    
    printf("double side circle List(%d) : post : ", l->cnt);
    for (int i = 0; i < (l->cnt << 1); ++i) {
        i && printf("->");
        printf("%d", p->data);
        p = p->front;
    }
    printf("\n");

}

void clear_node(Node *n) {
    if (!n) return ;
    free(n);
    return ;
}

void clear_list(List *l) {
    if (!l) return ;
    Node *p = l->head, *q;
    q = p->next;
    p->next = q->front = NULL;
    while(q) {
        p = q->next;
        clear_node(q);
        q = p;
    }
    free(l);
    return ;
}
