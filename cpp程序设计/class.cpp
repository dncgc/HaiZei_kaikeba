/*************************************************************************
	> File Name: class.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon 01 Mar 2021 10:45:00 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string; //工程开发中不建议使用using namespace std

class Cat {};

class Dog {};

class People {
public:
    string name;
    int age;
    double height;
    double weight;

    void say();
    void run();
};

void People::say() {
    cout << "this = " << this << endl;
    cout << "my name is " << name << endl;
}

int main() {
    People hug;
    People wangbo;
    hug.name = "Captain Hu";
    wangbo.name = "Wang Bo";
    cout << "&hug = " << &hug << endl;
    cout << "&wangbo = " << &wangbo << endl;
    hug.say();
    wangbo.say();
    
    return 0;
}
