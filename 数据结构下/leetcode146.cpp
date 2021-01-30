/*************************************************************************
	> File Name: leetcode146.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 30 Jan 2021 03:24:08 PM CST
 ************************************************************************/

#include <iostream>
#include <unordered_map>
using namespace std;
class LRUCache {
public:
    class Node {
    public:
        Node() : Node(0, 0) {}
        Node(int key, int value) : pre(nullptr), next(nullptr), key(key), value(value) {}
        Node *pre, *next;
        int key, value;
    };
    unordered_map<int, Node *> ind;
    int capacity, node_cnt;
    Node tail, head;

    LRUCache(int capacity) {
        this->capacity = capacity;
        this->node_cnt = 0;
        head.next = &tail;
        tail.pre = &head;
    }
    
    int get(int key) {
        if (ind.find(key) == ind.end()) return -1;
        Node *p = ind[key];
        remove_node(p);
        insert_tail(p);
        return p->value;
    }

    void output() {
        Node *p = head.next;
        while (p) {
            cout << "(" << p->key << ", " << p->value << ")->";
            p = p->next;
        }
        cout << endl;
        return ;
    }

    void insert_tail(Node *p) {
        p->next = &tail;
        p->pre = tail.pre;
        tail.pre->next = &tail;
        tail.pre = p;
        return ;
    }

    void remove_node(Node *p) {
        p->next->pre = p->pre;
        p->pre->next = p->next;
        return ;
    }

    void put(int key, int value) {
        Node *p;
        if (ind.find(key) == ind.end()) {
            p = new Node(key, value);
            node_cnt += 1;
            insert_tail(p);
            ind[key] = p;
        } else {
            get(key);
            ind[key]->value = value;
        }
        if (node_cnt > capacity) {
            p = head.next;
            remove_node(p);
            ind.erase(ind.find(p->key));
            delete p;
            node_cnt -= 1;
        }
        return ;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
