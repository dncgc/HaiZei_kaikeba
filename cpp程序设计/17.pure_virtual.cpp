/*************************************************************************
	> File Name: 14.Animal.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sun 07 Mar 2021 02:31:48 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Animal {
public:
    Animal(string name) : name(name) {}
    virtual void run() = 0; //声明成纯虚函数
    virtual void getName() final {}
    virtual void fl1() {}
private:
    string name;
};

class Cat : public Animal {
public:
    Cat(string name) : Animal(name) {}
    // final 代表子类不能重写，禁止子类出现同名函数
    void run() override  final { //父类是虚函数，子类同名的函数自动变为虚函数, override 主要为了帮我们规范化语义，让编译器帮忙找bug
        cout << "I can run with four legs" << endl;
    }
    // void fll() override {} //找出了BUG
};

class People : public Animal {
public:
    People(string name) : Animal(name) {}
    void run() {
        cout << "I can run with two legs" << endl;
    }
};

class Bat : public Animal {
public:
    Bat(string name) : Animal(name) {}
    void run() {
        cout << "I can fly" << endl;
    }
};

class House : public Animal {
public:
    House() : Animal("House") {}
    void run() override {
        cout << "House, I can run with four legs" << endl;
    }
};

int main() {
    House h;
}
