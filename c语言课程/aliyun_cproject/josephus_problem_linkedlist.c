/*************************************************************************
	> File Name: josephus_problem_linkedlist.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 09 Sep 2020 10:01:14 AM CST
用链表解决一个稍有改动的约瑟夫环问题
计算理工学院有 N 个同学，围成了一个圆圈，每人被顺序地编了一个序号（分别为 1,2,3... n1,2,3..n），从编号为 K 的人开始报 1，他之后（顺初始数字增长方向计算序号）的人报 2，以此类推，数到某一个数字 M 的人出列。出列同学的下一个人又从 1 开始继续报数，数到某一个数字 M的人出列。不断重复这一过程，直到所有人都出列为止。

你需要根据同学人数 N 和给出的 K 和 M 计算出同学的正确出列顺序。
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node *next;

} Node;

Node *circle_create(int n);
void count_off(Node *head, int n, int k, int m);

int main() {
    int n, k, m;
    scanf("%d%d%d", &n, &k, &m);
    Node *head = circle_create(n);
    count_off(head, n, k, m);
    return 0;

}

Node *circle_create(int n) {
    Node *temp, *new_node, *head;
    int i;

    // 创建第一个链表节点并加数据
    temp = (Node *) malloc(sizeof(Node));
    head = temp;
    head->data = 1;
    
    // 创建第 2 到第 n 个链表节点并加数据
    for(i = 2; i <= n; i++) {
        new_node = (Node *) malloc(sizeof(Node));
        new_node->data = i;
        temp->next = new_node;
        temp = new_node;
    }
    
    // 最后一个节点指向头部构成循环链表
    temp->next = head;

    return head;
}
    
void count_off(Node *head, int n, int k, int m) {
    Node *temp, *temp2;
    temp = head;
    if (k == 1) {
        for (int i = 1; i < n; i++) {
            temp = temp->next;
        }
    }
    else {
        for (int i = 1; i < k; i++) {
            temp = temp->next;
        }
    }
    while(temp->next != temp) {
        for (int j = 1; j < m-1; j++) {
            temp = temp->next;
        }
        printf("%d ", temp->next->data);
        temp2 = temp->next->next;
        temp->next->next = NULL;
        free(temp->next);
        temp->next = temp2;
        if (m != 1) temp = temp->next; 
       
    }
    printf("%d\n", temp->data);
    return;
}
