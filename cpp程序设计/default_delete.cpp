/*************************************************************************
	> File Name: default_delete.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 03 Mar 2021 09:05:00 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
public:
    /*A() = delete; //没有默认构造函数
    A(const A &) = default; //拷贝构造函数使用默认行为*/
    A() = default;
    A &operator=(int x) {
        this->x = x;
        return *this;
    }
    int x;
private: //使A类的对象无法被拷贝
    A (const A &) = delete;
    A &operator= (A &a);
    const A &operator=(const A &a) const;
};

int main() {
    A a;
    //A b;
    //a = b;
    (a = 123) = 456;
    cout << a.x << endl; //重载 <<运算符时要保证 cout << a.x 的返回值还是cout，所以要返回引用
    return 0;
}
