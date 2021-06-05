/*************************************************************************
	> File Name: 10.fib.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 01 Apr 2021 09:39:17 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int fib(int n) {
    if (n <= 2) return n;
    return fib(n - 1) + fib(n - 2);
}
