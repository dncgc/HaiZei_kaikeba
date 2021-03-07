/*************************************************************************
	> File Name: dynamic_cast.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sun 07 Mar 2021 04:37:13 PM CST
 ************************************************************************/
//动态类型转换

#include <iostream>
using namespace std;

class A {
public:
    A() {
        cout << "A constructor" << endl;
    }
    //virtual void say() {
    //    cout << "Class A" << endl;
    //}
    virtual ~A() {
        cout << "A destructor" << endl;
    }
};

class B : public A {
public:
    B() {
        cout << "B constructor" << endl;
    }
    //void say() override {
    //    cout << "Class B" << endl;
    //}
    virtual ~B() {
        cout << "B destructor" << endl;
    }
};

class C : public A {
public:
    C() {
        cout << "C constructor" << endl;
    }
    //void say() override {
    //    cout << "Class C" << endl;
    //}
    virtual ~C() {
        cout << "C destructor" << endl;
    }
};

void judge(A *p) {
    if (dynamic_cast<B *>(p)) {
        cout << p << "is class B" << endl;
    }
    if (dynamic_cast<C *>(p)) {
        cout << p << "is class C" << endl;
    }
    return ;
}

int main() {
    srand(time(0));
    A *p;
    switch (rand() % 2) {
        case 0: p = new B(); break;
        case 1: p = new C(); break;
    }
    cout << dynamic_cast<B *>(p) << endl; //将一个基类地址试着装换成子类地址,失败则返回空地址，通过指针存储的虚函数表来判断是哪一类
    cout << dynamic_cast<C *>(p) << endl;
    delete p;

    A *p1 = new B(), *p2 = new C();
    judge(p1), judge(p2);
    swap(((void **)p1)[0], ((void **)p2)[0]);
    judge(p1), judge(p2);
    return 0;
}
