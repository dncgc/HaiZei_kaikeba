/*************************************************************************
	> File Name: RVO.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 03 Mar 2021 07:48:59 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Data {
public:
    Data() {
        cout << "Data default constructor" << endl;
    }
    Data(const Data &a) {
        cout << "Data copy constructor" << endl;
    }
};

class A {
public:
    A() {
        cout << this << " " << "default constructor" << endl;
    }
    A(int x) : x(x) {
        cout << this << " " << "transform constructor" << endl;
    }
    A(const A &a) : x(a.x), d(a.d) { //写出初始化列表才会调用d的拷贝构造，默认的拷贝构造也会调用d的拷贝构造
        cout << this << " " << "copy constructor" << endl;
    }
    A &operator=(const A &a) {
        cout << this << " : operator=" << endl;
        return *this;
    }
    int x;
    Data d;
};

A func() {
    A temp(69);
    cout << "&temp = " << &temp << endl;
    return temp;
}

int main() {
    A a = func(); //对temp的所有行为都会反映到a对象上，则编译器对此进行优化，将this指针直接指向a，所以temp与a地址相同。
    cout << "&a = " << &a << endl;
    cout << a.x << endl;
    return 0;
}
