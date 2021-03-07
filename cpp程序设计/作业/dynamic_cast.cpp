/*************************************************************************
	> File Name: dynamic_cast.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sun 07 Mar 2021 05:54:33 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
public:
    virtual ~A() {
        cout << "A destructor" << endl;
    }
};

class B : public A {
public:
    virtual ~B() {
        cout << "B destructor" << endl;
    }
};

class C : public A {
public:
    virtual ~C() {
        cout << "C destructor" << endl;
    }
};

int main() {
    A *p;
    B b;
    C c;
    p = &b;
    cout << dynamic_cast<B *>(p) << endl;
    cout << dynamic_cast<C *>(p) << endl;

    ((void **)(&b))[0] = ((void **)(&c))[0];
    p = &b;
    cout << dynamic_cast<B *>(p) << endl;
    cout << dynamic_cast<C *>(p) << endl;
    return 0;
}
