/*************************************************************************
	> File Name: 42.lambda.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sun 28 Mar 2021 06:49:46 PM CST
 ************************************************************************/

#include <iostream>
#include <functional>
using namespace std;

function<int(int)> func(int x) {
    int n = 123;
    return [&](int k) -> int { return k * n + x; }; //使用值捕获就可以了
}

int main() {
    auto test = func(3); //会返回x、n 的无效引用, 引起重大BUG
    cout << test(3) << endl; //MAC正常，LinuxBUG
    //function<>
    auto add = [](int a, int b) -> int { return a + b; }; //-> 返回值后置
    auto add3 = [](int a, int b) -> int { return a + b; };
    function<int(int, int)> add2 = add;
    cout << add(3, 4) << endl;
    cout << typeid(add).name() << endl;
    cout << typeid(add2).name() << endl;
    cout << typeid(add3).name() << endl;

    int n = 12;
    //auto times = [n](int k) { //=: 前面变量全体值捕获 n: 部分捕获
        //cout << add(5, 6) << endl;
    auto times = [&](int k) {//&n: 引用捕获 &: 全体引用捕获
        return n * k;
    };
    cout << times(3) << endl; // 36, n = 12
    n = 14;
    cout << times(3) << endl; // 36, n = 12
    cout << test(3) << endl; //出现BUG

    return 0;
}
