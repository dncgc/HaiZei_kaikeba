/*************************************************************************
	> File Name: 22.nullptr.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 13 Mar 2021 03:26:38 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

void func(int x) {
    cout << __PRETTY_FUNCTION__ << endl;
    cout << x << endl;
}

void func(int *x) {
    cout << __PRETTY_FUNCTION__ << endl;
    cout << x << endl;
    return ;
}

int main() {
    //cout << NULL << endl;
    //cout << nullptr << endl;
    if (NULL) cout << "true" << endl;
    else cout << "false" << endl;
    if (nullptr) cout << "true" << endl;
    else cout << "false" << endl;
    func(nullptr);
    //func(NULL); 错误
    cout << typeid(NULL).name() << endl;
    cout << typeid(nullptr).name() << endl;
    return 0;
}
