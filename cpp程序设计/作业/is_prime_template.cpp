/*************************************************************************
	> File Name: is_prime_template.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 16 Mar 2021 10:14:43 PM CST
 ************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

template<int d, int n>
struct judge {
    static constexpr int r = (n % d == 0) ? 0 : judge<d - 1, n>::r;
};

template<int n>
struct judge<1, n> {
    static constexpr int r = 1;
};


template<int n>
struct is_prime {
    static constexpr int r = judge<(int)sqrt(n), n>::r ? 1 : 0;
};

int main() {
    cout << is_prime<2>::r << endl; // 1
    cout << is_prime<13>::r << endl; // 1
    cout << is_prime<25>::r << endl; // 0
    cout << is_prime<27>::r << endl; // 0
    cout << is_prime<9973>::r << endl; // 1
    return 0;
}
