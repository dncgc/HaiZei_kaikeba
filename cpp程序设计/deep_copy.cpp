/*************************************************************************
	> File Name: deep_copy.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 02 Mar 2021 04:47:26 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Array {
public:
    Array(int n = 10) {
        this->n = n;
        data = new int[n]; //malloc属于函数，new是运算符，可以自动调用拷贝函数
    }
    Array(const Array &a) {
        this->n = a.n;
        this->data = new int[this->n];
        for (int i = 0; i < this->n; i++) {
            this->data[i] = a.data[i];
        }
    }
    size_t size() const { return this->n; }
    int &operator[](int ind) {
        if (ind < 0 || ind >= n) return end;
        return data[ind];
    }
    const int &operator[](int ind) const {
        if (ind < 0 || ind >= n) return this->end;
        return this->data[ind];
    }

private:
    int *data, end;
    size_t n;
};

ostream &operator<<(ostream &out, const Array &a) {
    out << "Array(" << &a << ") : ";
    for (int i = 0; i < a.size(); i++) {
        i && out << " ";
        out << a[i]; //调用const类型的[]重载
    }
    return out;
}

int main() {
    Array a;
    for (int i = 0; i < a.size(); i++) {
        a[i] = rand() % 100; //调用非const类型的[]重载
    }
    cout << a << endl;
    Array b = a; //由于类中data是指针，则默认拷贝后两个data指向同一个空间，是浅拷贝;自己定义拷贝构造函数后成为了深拷贝。
    cout << b << endl;
    b[1] = 18432;
    cout << a << endl;
    cout << b << endl;
    return 0;
}
