/*************************************************************************
	> File Name: 34.bind.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 20 Mar 2021 08:14:46 PM CST
 ************************************************************************/

#include <iostream>
#include <functional>
using namespace std;

void func(int x) {
    cout << x << endl;
    return ;
}

void add(int a, int b) {
    cout << a << " + " << b << endl;
}

void test_ref(int &x) {
    x += 1;
    cout << "test_ref function" << endl;
    return ;
}

int main() {
    func(123);
    function<void()> f = bind(func, 123);
    cout << "================" << endl;
    f();
    function<void(int)> add3 = bind(add, 3, std::placeholders::_1); //参数占位符，预留出一个位置
    add3(45);
    add3(89);
    add3(100);
    //调换参数占位符，传入参数位置也会相应对调
    //占位符_1,代表新函数的第一个参数，而bind绑定按照原函数参数顺序
    function<void(int, int)> add2 = bind(add, std::placeholders::_2, std::placeholders::_1);
    add2(3, 4);
    int n = 0;
    function<void()> ref_func = bind(test_ref, ref(n)); //必须显示绑定引用
    cout << n << endl;
    ref_func();
    cout << n << endl;

    auto weird_func = bind(add, placeholders::_4, placeholders::_1);
    weird_func(1, 2, 3, 4);
    return 0;
}
