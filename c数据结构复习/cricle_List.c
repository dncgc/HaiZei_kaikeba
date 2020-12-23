/*************************************************************************
	> File Name: cricle_List.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 25 Nov 2020 01:59:29 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct CircleList {
    Node *head;
    int cnt;
} CircleList;

Node *init_node(int val) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->data = val;
    n->next = NULL;
    return n;
}

CircleList *init_list() {
    CircleList *cl = (CircleList *)malloc(sizeof(CircleList));
    cl->head = NULL;
    cl->cnt = 0;
    return cl;
}

int insert(CircleList *cl, int val, int ind) {
    if (!cl) return 0;
    if (ind < 0 || ind > cl->cnt) return 0;
    if (!cl->head) {
        cl->head = init_node(val);
        cl->head->next = cl->head;
    } else {
        Node *p = cl->head, *q = init_node(val);
        int n = ind;
        while (n--) p = p->next;
        q->next = p->next;
        p->next = q;
        if (ind == cl->cnt) cl->head = q;
    }
    ++cl->cnt;
    return 1;
}

void clear_node(Node *n) {
    if (!n) return ;
    free(n);
    return ;

}
int delete_node(CircleList *cl, int ind) {
    if (!cl) return 0;
    if (ind < 0 || ind >= cl->cnt) return 0;
    Node *p = cl->head, *q;
    int n = ind;
    while(n--) p = p->next;
    q = p->next;
    p->next = q->next;
    clear_node(q);
    if (ind == cl->cnt) cl->head = p;
    --cl->cnt;
    return 1;
}

void output(CircleList *cl) {
    printf("circlelist(%d) : ", cl->cnt);
    Node *p = cl->head;
    for (int i = 0; i < (cl->cnt << 1); ++i) {
        i && printf("->");
        printf("%d", p->next->data);
        p = p->next;
    }
    printf("\n");
    return ;
}

void clear_list(CircleList *cl) {
    if (!cl) return ;
    Node *p = cl->head->next, *q;
    cl->head->next = NULL;
    while (p) {
        q = p->next;
        clear_node(p);
        p = q;
    }
    free(cl);
}

int main() { 
    srand(time(0));
    #define max_op 20
    CircleList *cl = init_list();
    for (int i = 0; i < max_op; ++i) {
        int val = rand() % 100;
        int ind = rand() % (cl->cnt + 3) - 1;
        int op = rand() % 4;
        switch(op) {
            case 0:
            case 1:
            case 2: {
                printf("insert %d in the circlelist at %d = %d\n", val, ind, insert(cl, val, ind));
            } break;
            case 3: {
                printf("delete iterm in the circlelist at %d = %d\n", ind, delete_node(cl, ind));
            } break;
        }
        output(cl), printf("\n");
    }
    #undef max_op
    clear_list(cl);
    return 0;
}
