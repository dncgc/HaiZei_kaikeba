/*************************************************************************
	> File Name: operator.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 03 Mar 2021 10:44:40 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Point {
public:
    Point();
    Point(int x, int y);
    Point operator+(const Point &a);//类内重载优先级大于类外重载，不会冲突
    Point &operator+=(int);
private:
    friend Point operator+(const Point &a, const Point &);
    friend ostream &operator<<(ostream &out, const Point &);
    int x, y;
};

Point::Point() : Point(0, 0) {} //Point(0, 0) 称为委托构造
Point::Point(int x, int y) : x(x), y(y) {}
Point Point::operator+(const Point &a) { //类内重载优先级大于类外重载，不会冲突
    cout << "inner operator+" << endl;
    Point c(x + a.x, y + a.y);
    return c;
}
Point &Point::operator+=(int n) {
    x += n, y += n;
    return *this;
}

Point operator+(const Point &a, const Point &b) { //类外重载
    cout << "outer operator+" << endl;
    Point c(a.x + b.x, a.y + b.y);
    return c;
}

ostream &operator<<(ostream &out, const Point &a) {
    out << "(" << a.x << ", " << a.y << ")";
}

int main() {
    Point a(3, 4);
    Point b(7, 9);
    Point c = a + b; // a + b 表达式返回的是一个新的临时对象，重载+不用返回引用
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    a += 2; //该表达式返回a的值，所以重载+=返回引用，而且可以连续+=
    cout << a << endl;
    return 0;
}
