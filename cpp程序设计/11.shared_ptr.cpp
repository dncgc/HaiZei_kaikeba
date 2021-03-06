/*************************************************************************
	> File Name: 11.shared_ptr.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 06 Mar 2021 02:58:32 PM CST
 ************************************************************************/

#include <iostream>
#include <memory>
#include <unordered_map>
using namespace std;

namespace Haizei {

class A {
public:
    A() { cout << "default constructor" << endl; }
    int x, y;
    ~A() {
        cout << "destructor" << endl;
    }
};
/*
class My_shared_ptr {
public:
    My_shared_ptr(A *p) : p(p) {
        umap[p] += 1;
    }
    A *operator->() { return p; }
    A &operator*() { return *p; }
    int use_count() { return umap[p]; }
private:
    static unordered_map<A*, int> umap; 
    A *p;
};*/
class shared_ptr {
public:
    shared_ptr();
    shared_ptr(A *);
    shared_ptr(const shared_ptr &);
    int use_count();
    A *operator->();
    A &operator*();
    shared_ptr &operator=(const shared_ptr &p);
    ~shared_ptr();

private:
    void decreaseb_by_one();
    void increase_by_one();
    int *cnt;
    A *obj;
};

shared_ptr::shared_ptr() : obj(nullptr), cnt(nullptr) {}
shared_ptr::shared_ptr(A *obj) : obj(obj), cnt(new int(1)) {}
shared_ptr::shared_ptr(const shared_ptr &p) : obj(p.obj), cnt(p.cnt) { *p.cnt += 1; }
int shared_ptr::use_count() { return cnt ? *cnt : 0; }
A *shared_ptr::operator->() { return obj; }
A &shared_ptr::operator*() { return *obj; }
void shared_ptr::decreaseb_by_one() {
    if (this->cnt != nullptr) {
        *(this->cnt) -= 1;
        if (*(this->cnt) == 0) {
            delete this->obj;
            delete this->cnt;
        }
    }
    return ;
}

void shared_ptr::increase_by_one() {
    if (cnt != nullptr) {
        cnt[0] += 1;
    }
    return ;
}

shared_ptr &shared_ptr::operator=(const shared_ptr &p) {
    if (this->obj != p.obj) {
        decreaseb_by_one();
        obj = p.obj;
        cnt = p.cnt;
        increase_by_one();
    }
    return *this;
}
shared_ptr::~shared_ptr() {
    decreaseb_by_one();
    obj = nullptr;
    cnt = nullptr;
}

} // end of haizei

int main() {
    /*
    A *p1 = new A();
    p1 = nullptr;
    shared_ptr<A> p2(new A());
    cout << p2.use_count() << endl; // 1
    shared_ptr<A> p3 = p2;
    p2->x = 123; p2->y = 456;
    (*p2).x = 456;
    cout << p2.use_count() << endl; // 2
    p2 = nullptr; // 自动析构，不会发生内存泄漏
    cout << p3.use_count() << endl << endl; // 1
    */
    Haizei::A *p1 = new Haizei::A();
    p1 = nullptr;
    Haizei::shared_ptr p2(new Haizei::A());
    cout << p2.use_count() << endl; // 1
    Haizei::shared_ptr p3 = p2;
    p2->x = 123; p2->y = 456;
    (*p2).x = 456;
    cout << p2.use_count() << endl; // 2
    p2 = nullptr; // 自动析构，不会发生内存泄漏
    cout << p3.use_count() << endl; // 1
    p2 = p3;
    cout << p3.use_count() << endl; // 2
    return 0;
}
