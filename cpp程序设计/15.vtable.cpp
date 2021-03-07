/*************************************************************************
	> File Name: 15.vtable.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sun 07 Mar 2021 03:27:04 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
public:
    A() { this->x = 200; this->y = 400; }
    virtual void say(int x) {
        cout << "this->x = " << this->x << endl;
        cout << "Class A say : " << x  << endl;
    }
    virtual void run() {
        cout << "Class A run" << endl;
    }
    void reg1() {
        cout << "reg1 function " << endl;
    }
    void reg2() {
        cout << "reg1 function " << endl;
    }
    void reg3() {
        cout << "reg1 function " << endl;
    }
    int x, y;
};

class B : public A {
public:
    B() { x = 300; }
    void say(int x) override {  //底层其实会隐藏传入this指针
        cout << "Class B say : " << x << endl;
    }
};

class C : public A {
public:
    C() { x = 400; }
    void run() override {
        cout << "Class C run" << endl;
    }
};

#define TEST(a) test(a, #a)
void test(A &a, string class_name) {
    cout << "Object " << class_name << endl;
    a.say(123);
    a.run();
    cout << "==================" << endl << endl;
    return ;
}

typedef void (*func)(void *, int);

int main() {
    A a;
    B b;
    C c;
    TEST(a);
    TEST(b);
    TEST(c);

    ((void **)(&b))[0] = ((void **)(&c))[0];
    TEST(b);

    ((func**)(&b))[0][0](&b, 100); //不传this指针不能实现同样功能

    void (A::*p)(int); //定义成员方法指针
    p = &A::say;
    (a.*p)(12345); //成员方法指针要与对象绑定来使用

    void (A::*q[3])();
    q[0] = &A::reg1;
    q[1] = &A::reg2;
    q[2] = &A::reg3;
    for (int i = 0; i < 10; i++) {
        (a.*q[rand() % 3])();
    }

    int A::*pq;  //定义成员属性指针
    pq = &A::x;
    cout << (a.*pq) << endl;
    pq = &A::y;
    cout << (a.*pq) << endl;
    return 0;
}
