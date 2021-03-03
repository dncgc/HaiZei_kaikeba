/*************************************************************************
	> File Name: constructor.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 02 Mar 2021 03:45:32 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

class Data {
public:
    Data(int x, int y) : x(x), y(y) {
        cout << "data : " << this << endl;
    }
    friend ostream &operator<<(ostream &out, const Data &d); //声明友元函数。
private:
    int x, y;
};

class A {
public:
    A() : d(3, 4), c(3, 4) {
        cout << this << " : constructor" << endl;
        cout << "c : " << &c << endl;
        cout << "d : " << &d << endl;
    }
    A(int x) : d(x, x), c(3, 4) {
        cout << this << " : transform constructor" << endl;
    }
    A(const A &a) : d(a.d), c(3, 4) { // 兼容处理const 和 非const场景
        cout << this << " : copy constructor" << endl;
    } //写成A(A a)就无限套娃了
    A &operator=(const A &a) {
        cout << this << " : operator=" << endl;
        return *this;
    }
    ~A() {
        cout << this << " : destructor" << endl;
    }
    Data c, d;
};

void add_one(int &x) { //(左值)引用,传引用不会产生任何拷贝行为
    x += 1;
    return ;
}

ostream &operator<<(ostream &out, const Data &d) {
    out <<  "(" << d.x << ", " << d.y << ")";
    return out;
}

int main() {
    Data d(10, 9);
    cout << d << endl;
    int n = 3;
    cout << "n = " << n << endl;
    add_one(n);
    cout << "n = " << n << endl;
    A a;
    A b = a; // 定义对象时 = 等价于 A b(a);
    A c = 3; // 等价于 A c(3);
    a = 123; //首先调用赋值运算符，然后调用转换构造函数将123转换成临时的匿名对象，然后再将匿名对象绑定到传入参数a中，然后再进入到重载的赋值运算符过程中
    cout << "end of main" << endl;
    return 0;
}
