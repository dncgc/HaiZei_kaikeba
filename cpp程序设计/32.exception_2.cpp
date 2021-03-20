/*************************************************************************
	> File Name: 32.exception_2.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 20 Mar 2021 02:51:25 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <exception>
using namespace std;

void Process(int v) {
    if (v > 3) {
        throw runtime_error("number too big");
    }
}

int main() {
    vector<int> v = {1, 2, 3, 4, 5 };
    for (int i = 0; i < 5; ++i) {
        try {
            Process(v[i]);
            cout << v[i] << endl;
        }
        catch (runtime_error &e) {
            cout << e.what() << endl;
        }
    }
    return 0;
}
