/*************************************************************************
	> File Name: euler6.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 22 Dec 2020 07:19:41 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    int psum = 0, sump = 0;
    for (int i = 1; i <= 100; i++) {
        psum += i * i;
        sump += i;
    }
    sump *= sump;
    cout << sump - psum << endl;
    return 0;
}
