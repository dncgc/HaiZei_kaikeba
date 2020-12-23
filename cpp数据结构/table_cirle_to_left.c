/*************************************************************************
	> File Name: table_cirle_to_left.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 05 Dec 2020 03:48:57 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Table {
    int *data;
    int size;
} Table;

Table *init(int n) {
    Table *t = (Table *)malloc(sizeof(Table));
    t->data = (int *)malloc(sizeof(int) * n);
    t->size = n;
    return t;
}

void table_moveleft(Table *t, int k) {
    int *temp = (int *)malloc(sizeof(int) * t->size);
    int j = 0;
    for (int i = k; i < t->size; i++) temp[j++] = t->data[i];
    for (int i = 0; i < k; i++) temp[j++] = t->data[i];
    free(t->data);
    t->data = temp;
    return ;
}

void table_output(Table *t) {
    for (int i = 0; i < t->size; i++) {
        i && printf(" ");
        printf("%d", t->data[i]);
    }
    printf("\n");
    return ;
}

void clear(Table *t) {
    if (!t) return ;
    free(t->data);
    free(t);
    return ;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    Table *t = init(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", t->data + i);
    }
    table_moveleft(t, k);
    table_output(t);
    return 0;
}
