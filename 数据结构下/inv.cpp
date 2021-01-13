/*************************************************************************
	> File Name: 1.inv.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 13 Jan 2021 06:54:47 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 1000
int inv[7];

int main() {
    inv[1] = 1;
    for (int i = 2; i < 7; i++) {
        inv[i] = ((-(7 / i) * inv[7 % i]) % 7 + 7) % 7;
        cout << i << " : " << inv[i] << endl;
    }
    return 0;
}
