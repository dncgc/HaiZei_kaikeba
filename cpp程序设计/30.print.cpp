/*************************************************************************
	> File Name: 30.print.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sun 14 Mar 2021 03:34:53 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

template<typename T, typename ...ARGS>
struct N_ARGS {
    typedef T type;
    typedef N_ARGS<ARGS...> rest;
};

template<typename T>
struct N_ARGS<T> {
    typedef T type;
    typedef T last; //定义两个名字，一个作用是确定是否是最后一个类型
};

template<int N, typename T, typename ...ARGS>
struct New_N_ARGS {
    typedef typename New_N_ARGS<N-1, ARGS...>::type type;
    static int last() {
        return New_N_ARGS<N - 1, ARGS...>::last();
    }
};

template<typename T, typename ...ARGS>
struct New_N_ARGS<1, T, ARGS...> {
    typedef T type;
    static int last() { return 0; }
};

template<typename T>
struct New_N_ARGS<1, T> {
    typedef T type;
    static int last() { return 1; }
};

template<typename T>
void print(T a) {
    cout << a << endl;
    return; 
}

template<typename T, typename ...ARGS>
void print(T a, ARGS... args) {
    cout << a << " next type : " << typeid(typename N_ARGS<ARGS...>::type).name() << endl;
    print(args...);
    return ;
}

#define Test(func...) cout << #func << " = " << func << endl;

int main() {
    print(123, 45.6);
    print("hello", "world");
    print(123, "hello world", "haizei", 45.6);
    N_ARGS<int, int, double, double>::type x;
    N_ARGS<int, int, double, double>::rest::type y;
    N_ARGS<int, int, double, double>::rest::rest::type z;
    N_ARGS<int, int, double, double>::rest::rest::rest::last w;
    New_N_ARGS<1, int, int, double, double>::type x1;
    New_N_ARGS<2, int, int, double, double>::type y1;
    New_N_ARGS<3, int, int, double, double>::type z1;
    New_N_ARGS<4, int, int, double, double>::type w1;

    Test(New_N_ARGS<1, int, int, double, double>::last());
    Test(New_N_ARGS<2, int, int, double, double>::last());
    Test(New_N_ARGS<3, int, int, double, double>::last());
    Test(New_N_ARGS<4, int, int, double, double>::last());

    cout << typeid(x).name() << endl;
    cout << typeid(y).name() << endl;
    cout << typeid(z).name() << endl;
    cout << typeid(w).name() << endl;
    cout << typeid(x1).name() << endl;
    cout << typeid(y1).name() << endl;
    cout << typeid(z1).name() << endl;
    cout << typeid(w1).name() << endl;
    return 0;
}
