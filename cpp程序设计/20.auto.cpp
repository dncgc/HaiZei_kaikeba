/*************************************************************************
	> File Name: 20.auto.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 13 Mar 2021 02:11:30 PM CST
 ************************************************************************/

#include <iostream>
#include <map>
using namespace std;

class Base {
public:
    static int x;
private:
};

auto Base::x = 3;

int main() {

    int x;
    auto y = 12.3; // c++11 中最大作用就是简化代码, 在14、17标准中在模板中很强大
    
    if (typeid(y).hash_code() == typeid(float).hash_code()) {
        cout << "float type" << endl;
    }
    if (typeid(y).hash_code() == typeid(double).hash_code()) {
        cout << "double type" << endl;
    }

    Base b;
    cout << typeid(b).name() << endl;
    cout << typeid(x).name() << endl;
    cout << typeid(y).name() << endl;
    // auto int z = 123; //c语言的用法，局部的自动变量，其实与局部变量没有区别，所以c中没什么用
    map<int, int> arr;
    for (int i = 0; i < 10; i++) {
        arr[rand() % 100] = rand();
    }
    // map<int, int>::iterator iter = arr.begin();
    auto iter = arr.begin();
    cout << sizeof(iter) << endl;
    while (iter != arr.end()) {
        cout << iter->first << " " << iter->second << endl;
        iter++;
    }
    for (pair<int, int> x : arr) { //与 auto x : arr 等价
        cout << x.first << " " << x.second << endl;
    }

    cout << sizeof(x) << endl;
    cout << sizeof(y) << endl;
    return 0;
}
