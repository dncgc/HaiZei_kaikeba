/*************************************************************************
	> File Name: 1.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 15 Sep 2021 03:42:47 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
struct ListNode {
    ListNode(int val, ListNode *next = nullptr) : val(val), next(next) {}
    int val;
    ListNode *next;

};
ListNode *reverse(ListNode *head) {
    if (head == nullptr) return head;
    ListNode *q = head, *p = head->next;
    q->next = nullptr;
    while (p) {
        ListNode *n = p->next;
        p->next = q;
        q = p;
        p = n;    
    }
    return q;

}

int length(ListNode *head) {
    int ans = 0;
    ListNode *p = head;
    while (p) ans += 1, p = p->next;
    return ans;
}

ListNode *add(ListNode *head1, ListNode *head2) {
    head1 = reverse(head1);
    head2 = reverse(head2);
    ListNode *p, *q, *tail, *newHead;
    if (length(head1) >= length(head2)) p = head1, q = head2;
    else p = head2, q = head1;
    tail = newHead = p;
    int n = 0;
    while (p) {
        int numq = q ? q->val : 0;
        p->val += numq + n;
        n = p->val / 10;
        p->val %= 10;
        tail = p;
        p = p->next;
        q = q ? q->next : q;
    }
    if (n) tail->next = new ListNode(n);
    return reverse(newHead);
}

void output(ListNode *newHead) {
    ListNode *p = newHead;
    while (p) {
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
    return ;
}

int main() {
    ListNode *head1 = new ListNode(3);
    // head1->next = new ListNode(4);
    // head1->next->next = new ListNode(2);
    output(head1);
    ListNode *head2 = new ListNode(9);
    head2->next = new ListNode(4);
    // head2->next->next = new ListNode(9);
    output(head2);
    output(add(head1, head2));
    return 0;

}
