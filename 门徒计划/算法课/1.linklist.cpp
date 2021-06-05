/*************************************************************************
	> File Name: 1.linklist.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 17 Mar 2021 11:31:09 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

struct Node {
    Node(int data) :data(data), next(NULL) {}
    int data;
    struct Node *next;
};

Node *reverse(Node *head, int n) {
    if(n == 1) return head;
    Node *tail = head->next, *p = reverse(head->next, n - 1);
    head->next = tail->next;
    tail->next = head;
    return p;
}

int main() {
    Node *head = NULL;
    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head = reverse(head, 2);
    Node *p = head;
    while (p != NULL) {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("\n");
    return 0;
}
