/*************************************************************************
	> File Name: 31.is_prime.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sun 14 Mar 2021 04:49:04 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

template<int N>
struct is_prime {
    static constexpr int r = 0;
};

template<int n>
struct sum {
    static constexpr int r = n + sum<n - 1>::r;
};

template<>
struct sum<1> {
    static constexpr int r = 1;
};

template<int n>
struct getBad {
    static constexpr int r = (n <= 5);
    static constexpr int s = (n % 2 == 1);
};

template<int n>
struct getGood {
    static constexpr int r = (n > 5);
    static constexpr int s = (n % 2 == 0);
};

template<int n, int m> struct judge;
template<> 
struct judge<1, 0> {
    static constexpr char *r = (char *)"bad";
    static constexpr char *s = (char *)"not";
};

template<int n, int m> struct judge;
template<> 
struct judge<0, 1> {
    static constexpr char *r = (char *)"good";
    static constexpr char *s = (char *)"yes";
};

template<int n>
struct score {
    static constexpr char *r = judge<getBad<n>::r, getGood<n>::r>::r;
};

template<int n>
struct isEven {
    static constexpr int r = n % 2;
};

template<int n> struct judge1;
template<> 
struct judge1<0> {
    static constexpr char *r = (char *)"yes";
};

template<int n> struct judge1;
template<> 
struct judge1<1> {
    static constexpr char *r = (char *)"no";
};

template<int n>
struct is_even {
    static constexpr char *r = judge1<isEven<n>::r>::r;
    //static constexpr char *r = judge<getBad<n>::s, getGood<n>::s>::s;
};

int main() {
    cout << sum<5>::r << endl;  // for
    cout << score<10>::r << endl; // good, if
    cout << score<4>::r << endl; // bad, if
    cout << is_even<3>::r << endl; // not
    cout << is_even<4>::r << endl; // yes
    cout << is_prime<2>::r << endl; // 1
    cout << is_prime<13>::r << endl; // 1
    cout << is_prime<25>::r << endl; // 0
    cout << is_prime<27>::r << endl; // 0
    cout << is_prime<9973>::r << endl; // 1
    return 0;
}
