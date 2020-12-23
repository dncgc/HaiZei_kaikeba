/*************************************************************************
	> File Name: table_to_tree.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 26 Nov 2020 01:34:36 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node *lchild, *rchild;
} Node;

typedef struct Tree {
    Node *root;
    int n;
} Tree;

typedef struct Stack {
    Node **data;
    int top, size;
} Stack;

Node *getNewNode(char val) {
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = val;
    p->lchild = p->rchild = NULL;
    return p;
}

Tree *getNewTree() {
    Tree *tree = (Tree *)malloc(sizeof(Tree));
    tree->root = NULL;
    tree->n = 0;
    return tree;
}

Stack *init_stack(int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = (Node **)malloc(sizeof(Node *));
    s->top  = -1;
    s->size = n;
    return s;
}

Node *top(Stack *s) {
    return s->data[s->top];
}

int empty(Stack *s) {
    return s->top == -1;
}

int push(Stack *s, Node *val) {
    if (!s) return 0;
    if (s->top == s->size - 1) return 0;
    s->data[++s->top] = val;
    return 1;
}

int pop(Stack *s) {
    if (!s) return 0;
    if (empty(s)) return 0;
    s->top -= 1;
    return 1;
}

void clear_stack(Stack *s) {
    if (!s) return ;
    free(s->data);
    free(s);
    return ;
}

void clear_node(Node *node) {
    if (!node) return ;
    clear_node(node->lchild);
    clear_node(node->rchild);
    free(node);
    return ;
}

void clear_tree(Tree *tree) {
    if (!tree) return ;
    clear_node(tree->root);
    free(tree);
    return ;
}

Node *build(const char *str, int *node_num) {
    Stack *s = init_stack(strlen(str));
    Node *temp = NULL, *p = NULL;
    int flag = 0;
    while (str[0]) {
        switch (str[0]) {
            case '(':
                push(s, temp);
                flag = 0;
                break;
            case ')':
                p = top(s);
                pop(s);
                break;
            case ',': flag = 1; break;
            case ' ': break;
            default: 
                temp = getNewNode(str[0]);
            if (!empty(s) && flag == 0) {
                top(s)->lchild = temp;
            } else if (!empty(s) && flag == 1) {
                top(s)->rchild = temp;
            }
            ++(*node_num);
            break;
        }
        ++str;
    }
    clear_stack(s);
    if (temp && !p) p = temp;
    return p;
}

void pre_order_node(Node *node) {
    if (!node) return ;
    printf("%c ", node->data);
    pre_order_node(node->lchild);
    pre_order_node(node->rchild);
    return ;
}

void pre_order(Tree *tree) {
    if (!tree) return ;
    printf("pre_order : ");
    pre_order_node(tree->root);
    printf("\n");
    return ;
}

void in_order_node(Node *node) {
    if (!node) return ;
    in_order_node(node->lchild);
    printf("%c ", node->data);
    in_order_node(node->rchild);
    return ;
}

void in_order(Tree *tree) {
    if (!tree) return ;
    printf("in_order : ");
    in_order_node(tree->root);
    printf("\n");
    return ;
}
void post_order_node(Node *node) {
    if (!node) return ;
    post_order_node(node->lchild);
    post_order_node(node->rchild);
    printf("%c ", node->data);
    return ;
}

void post_order(Tree *tree) {
    if (!tree) return ;
    printf("post_order : ");
    post_order_node(tree->root);
    printf("\n");
    return ;
}

int main() {
    char str[1000] = {0};
    int node_num = 0;
    scanf("%[^\n]s", str);
    Tree *tree = getNewTree();
    tree->root = build(str, &node_num);
    tree->n = node_num;
    pre_order(tree);
    in_order(tree);
    post_order(tree);
    clear_tree(tree);
    return 0;
}
