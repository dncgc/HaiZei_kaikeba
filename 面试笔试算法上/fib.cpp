/*************************************************************************
	> File Name: fib.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 22 Dec 2020 08:45:49 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

long long num[50];

long long func(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (num[n]) return num[n];
    return num[n] = func(n - 1) + func(n - 2);
}

int main() {
    int n;
    cin >> n;
    cout << func(n) << endl;
    return 0;
}
