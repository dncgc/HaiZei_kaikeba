/*************************************************************************
	> File Name: 1.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 13 Oct 2021 08:00:07 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Node {
public:
    int num;
    Node *next;
    Node() {}
    Node(int num, Node *next = nullptr) : num(num), next(next) {}
};


void output(Node *head) {
    Node *p = head;
    while (p) {
        p == head || cout << ",";
        cout << p->num;
        p = p->next;
    }
    cout << endl;
}

void reverse(Node *head) {
    if (head->next->next == nullptr) return ;
    Node *p = head->next, *q = p->next, *k = q ? q->next : q;
    if (p == head->next) p->next = nullptr;
    while (q) {
        q->next = p;
        p = q;
        q = k;
        k = q ? q->next : q;
    }
    head->next = p;
    return ;
}

int main() {
    string nums;
    Node *head = nullptr, *p = nullptr;
    cin >> nums;
    int begin = 0;
    for (int i = 0; i < nums.size(); i++) {
        while (nums[i] && nums[i] != ',') i++;
        int t = atoi(nums.substr(begin, i - begin).c_str());
        if (begin == 0) head = new Node(t), p = head;
        else p->next = new Node(t), p = p->next;
        begin = i + 1;
    }
    output(head);
    p = head;
    while (p->next->next) reverse(p), p = p->next;
    output(head);
    return 0;

}
