/*************************************************************************
	> File Name: 6.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 04 Feb 2021 09:22:12 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    int pa = 0, ad = 0;
    for (int i = 1; i <= 100; i++) {
        pa += i * i;
        ad += i;
    }
    cout << ad * ad - pa << endl;
    return 0;
}
