/*************************************************************************
	> File Name: 21.constexpr.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 13 Mar 2021 02:56:59 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

constexpr int func(int x) {
    if (x == 1) return 1;
    return x * func(x - 1);
}

constexpr int f(int x) {
    return 2 * x;
}

class A {
public:
    constexpr A(int x) {}
};

int main() {
    int n;
    cin >> n;
    const int x = n + 123;
    //constexpr int y = n + 123; //错误用法
    constexpr int y1 = 123;
    constexpr int y2 = f(123);
    constexpr int y3 = func(1);
    cout << y3 << endl;
    const A a(123);
    constexpr A b(123);

    /* const int x = 123; //运行期常量
    constexpr int y = 123; //表达式常量，也就是编译期常量
    *(const_cast<int *>(&x)) = 456;
    *(const_cast<int *>(&y)) = 456;
    cout << &x << endl;
    cout << &y << endl;
    cout << const_cast<int *>(&x) << endl;
    cout << const_cast<int *>(&y) << endl;
    cout << *(&x) << endl;
    cout << *(&y) << endl;
    //x = 456; //都会报错
    //y = 456; */
    return 0;
}
