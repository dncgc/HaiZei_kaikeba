/*************************************************************************
	> File Name: malloc_new.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 02 Mar 2021 05:38:40 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A {
public:
    A() {
        cout << "default constructor" << endl;
    }
    ~A() {
        cout << "destructor" << endl;
    }
};

class B {
public:
    B() {
        cout << "B default constructor" << endl;
    }
};

int main() {
    int n = 10;
    cout << "malloc int" << endl;
    int *data1 = (int *)malloc(sizeof(int) * n);
    free(data1);
    cout << "new int" << endl;
    int *data2 = new int[n];
    delete[] data2;
    cout << "malloc A" << endl;
    A *Adata1 = (A *)malloc(sizeof(A) * n);
    for (int i = 0; i < n; i++) {
        new(Adata1 + i) A(); //原地构造，传入构造对象的首地址,后面加要使用的构造函数，理论上可以加别的类的构造函数。
    }
    free(Adata1);
    cout << "new A" << endl;
    A *Adata2 = new A[n];
    A *Adata3 = new A;
    delete[] Adata2;
    delete Adata3;
    return 0;
}
