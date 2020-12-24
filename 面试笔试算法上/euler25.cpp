/*************************************************************************
	> File Name: euler25.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 24 Dec 2020 06:35:24 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int func(int *n1, int *n2) {//加和进位一起处理
    n2[0] = n1[0];
    for (int i = 1; i <= n2[0]; i++) {
        n2[i] += n1[i];
        if (n2[i] > 9) {
            n2[i + 1] += n2[i] / 10;
            n2[i] %= 10;
            if (i == n2[0]) {
                n2[0]++;
            }
        }
    }
    return n2[0] >= 1000;
}

int main() {
    int num[2][1100] = {{1, 1}, {1, 1}};//1位数，数字为1
    int a = 0, b = 1;
    for (int i = 3; 1; i++) {
        if (func(num[a], num[b])) {
            cout << i << endl;
            break;
        }
        swap(a, b);
    }
    return 0;
}
