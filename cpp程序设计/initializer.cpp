/*************************************************************************
	> File Name: const.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 27 Feb 2021 03:55:08 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
public:
    //不论x、y谁在前，实际初始化顺序都是与定义顺序相同
    A() : x(123), y(x + 1) {} //调用的构造函数，对于内建类型没有区别
    //{x = 123; y = 0;} 使用的赋值运算符
    void say1 () const { //const类型方法，不修改对象的成员属性,让编译器帮助找逻辑错误。
        cout << y << endl;
        y += 1;    //逻辑上的const，虽然被改了，但是不影响
    }
    void say2() {

    }
    int x;
    mutable int y;
};

int main() {
    //const int a = 1; //数据意义上的const，不能更改
    const A a;
    a.say1();
    //a.say2(); 
    //a为常量对象，不能更改，而say2成员函数有可能更改成员属性，所以出错
    return 0;
}
