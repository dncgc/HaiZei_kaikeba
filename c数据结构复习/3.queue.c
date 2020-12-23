/*************************************************************************
	> File Name: 3.queue.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 25 Nov 2020 11:50:38 AM CST
 ************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define GREEN(a) COLOR(a, 32)

typedef struct Queue {
    int *data;
    int head, tail, length, cnt;
} Queue;

Queue *init(int n) {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)malloc(sizeof(int) * n);
    q->length = n;
    q->head = q->tail = q->cnt = 0;
    return q;
}

int front(Queue *q) {
    return q->data[q->head];
}

int isempty(Queue *q) {
    return q->cnt == 0;
}

int expand(Queue *q) {
    int extr_size = q->length;
    int *p;
    while (extr_size) {
        p = (int *)malloc(sizeof(int) * (q->length + extr_size));
        if (p) break;
        extr_size >>= 1;
    }
    if (!p) return 0;
    for (int i = q->head, j = 0; j < q->cnt; ++i, ++j) {
        p[j] = q->data[i % q->length];
    }
    free(q->data);
    q->data = p;
    q->length += extr_size;
    q->head = 0;
    q->tail = q->cnt;
    return 1;
}

int push(Queue *q, int val) {
    if (!q) return 0;
    if (q->cnt == q->length) {
        if (!expand(q)) return 0;
        printf(GREEN("expand successfully! Queue->size(%d)\n"), q->length);
    }
    q->data[q->tail++] = val;
    if (q->tail == q->length) q->tail = 0;
    q->cnt += 1;
    return 1;
}

int pop(Queue *q) {
    if (!q) return 0;
    if (isempty(q)) return 0;
    q->head++;
    if (q->head == q->length) q->head = 0;
    q->cnt -= 1;
    return 1;
}

void output(Queue *q) {
    printf("Queue : [");
    for (int i = q->head, j = 0; j < q->cnt; ++i, ++j) {
        i == q->head || printf(", ");
        printf("%d", q->data[i % q->length]);
    }
    printf("]\n");
    return ;
}

void clear(Queue *q) {
    if (!q) return ;
    free(q->data);
    free(q);
    return ;
}

int main() {
    srand(time(0));
    #define max_op 20
    Queue *q = init(max_op);
    for (int i = 0; i < (max_op << 1); ++i) {
        int val = rand() % 100;
        int op = rand() % 4;
        switch (op) {
            case 0:
            case 1:
            case 2: {
                printf("push %d to the Queue = %d\n", val, push(q, val));
            } break;
            case 3: {
                int f = front(q);
                printf("pop %d from the Queue = %d\n", f, pop(q));
            } break;
        }
        output(q), printf("\n");
    }
    #undef max_op
    clear(q);
    return 0;
}
