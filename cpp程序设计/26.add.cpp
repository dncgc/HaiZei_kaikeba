/*************************************************************************
	> File Name: 26.add.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 13 Mar 2021 08:24:34 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
public:
    A() = delete;
    A(int x) : x(x) {}
    A operator+(const A &a) {
        return A(x + a.x);
    }
    friend ostream &operator<<(ostream &, const A &);

private:
    int x;
};

ostream &operator<<(ostream &out, const A &a) {
    out << a.x;
    return out;
}

//以下4行代码为模板的声明,工程中要实现到头文件中
/*template<typename T, typename U>
decltype(T() + U()) add(T a, U b) {  //类型朽化, 自动判断类型,如果没有默认构造就会出错
    return a + b;
}*/

template<typename T, typename U>
auto add(T a, U b) -> decltype(a + b) {  //无 bug 版
    return a + b;
}

auto func(int a, int b) -> int {   //返回值后置
    return a + b;
}

/*
template<typename T1, typename T2>
T1 add(T1 a, T2 b) {  //c++14 可以用auto
    return a + b;
}
*/

int main() {
    A a(3), b(5);
    cout << a + b << endl;
    cout << add(a, b) << endl;
    cout << add(1, 2) << endl;
    cout << add(1.5, 2.8) << endl;
    //cout << add<double>(3, 1.5) << endl; //显示调用模板
    cout << add(3, 1.5) << endl;
    decltype(1 + 2) x;  //等价于定义了整型变量x
    cout << typeid(x).name() << endl;
    return 0;
}
