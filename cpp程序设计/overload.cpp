/*************************************************************************
	> File Name: overload.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 03 Mar 2021 10:21:59 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

double func(double x) {
    return x * x;
}

// func(int)
//double func(int x) {
//    return x * x + 5;
//}

// func(int)
// func(int, int)
int func(int x, int y = 2) { //由参数默认值可能与func(int x)产生冲突
    return x * y;
}

int main() {
    cout << func(2) << endl;
    cout << func(2.3) << endl;
    cout << func(2, 4) << endl;
    return 0;
}
