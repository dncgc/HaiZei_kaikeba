/*************************************************************************
	> File Name: 32.exception.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 20 Mar 2021 02:06:01 PM CST
 ************************************************************************/

#include <iostream>
#include <exception>
using namespace std;

class Helper {
public:
    Helper() { cout << "Helper constructor" << endl; }
    ~Helper() { cout << "Helper deconstructor" << endl; }
};

class idontknowwhatshappening : public exception {
public:
    idontknowwhatshappening() = default;
    ~idontknowwhatshappening() = default;
    idontknowwhatshappening& operator=(const idontknowwhatshappening&) = default;
    const char* what() { return "I don't know what's happening.\n"; };
};

void inner() {
    try {
        throw(idontknowwhatshappening());
    }
    catch(idontknowwhatshappening &e) {
        cout << e.what() << endl;
    }
    catch (exception &e) {
        cout << "e" << endl;
    }
}

void outer() {
    try {
        inner();
    }
    catch (...) { //接收任意类型的异常
        cout << "exception caught" << endl;
    }
    return ;
}

int main() {
    try {
        Helper *h = new Helper();
        throw("123");
    }
    catch(...) {
        cout << "exception caught" << endl;
    }
    /*
    int age = 100;
    try {
        if (age > 90) {
            throw(age);
            cout << "123" << endl; //不会被执行
        }
    }
    catch (int age) {
        cout << age << " is too big" << endl;
    }
    */
    return 0;
}
