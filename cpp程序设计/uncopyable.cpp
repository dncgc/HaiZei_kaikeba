/*************************************************************************
	> File Name: uncopyable.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 06 Mar 2021 08:38:43 PM CST
 ************************************************************************/
// 实现ABC三个类不能被拷贝的功能

#include <iostream>
using namespace std;

class Uncopyable {
public:
    Uncopyable() = default;
    Uncopyable(const Uncopyable &) = delete;
    Uncopyable &operator=(const Uncopyable &) = delete;
};

class A : public Uncopyable {};
class B : public Uncopyable {};
class C : public Uncopyable {};

int a(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

int main() {
    A a;
    A c = a;
    return 0;
}
