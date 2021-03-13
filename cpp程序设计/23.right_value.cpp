/*************************************************************************
	> File Name: 23.right_value.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 13 Mar 2021 03:43:18 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

#define func(x) __func(x, "func(" #x ")")
#define func2(x) __func2(x, "func2(" #x ")")

void __func2(int &x, const char *str) {
    cout << str << " is left value" << endl;
    return ;
}

void __func2(int &&x, const char *str) { //两个&&是右值引用
    cout << str << " is right value" << endl;
    return ;
}

void __func2(double &&x, const char *str) {
    cout << str << "is double value" << endl;
    return ;
}

void __func(int &x, const char *str) {
    cout << str << " is left value" << endl;
    func2(x);
    return ;
}

void __func(int &&x, const char *str) { //两个&&是右值引用
    cout << str << " is right value" << endl;
    func2(forward<double &&>(x));  //move 强制性变为右值特性, forward 希望向前传递什么类型的值
    return ;
}

namespace haizei {

class vector {
public:
    vector(int n = 10) : __size(n), data(new int[n]) {
        cout << "default constructor" << endl;
    }
    vector(const vector &v) : __size(v.size()), data(new int[__size]) {
        cout << "deep copy constructor" << endl;
        for (int i = 0; i < size(); i++) data[i] = v[i];
        return ;
    }
    vector(vector &&v) : __size(v.size()), data(v.data){
        cout << "move copy constructor" << endl;
        v.data = nullptr; //注意将数据抢过来后清空原对象存储区
        v.__size = 0;
    }
    vector operator+(const vector &v) {
        vector ret(v.size() + this->size());
        vector &now = *this;
        for (int i = 0; i < size(); i++) {
            ret[i] = now[i];
        }
        for (int i = size(); i < ret.size(); i++) {
            ret[i] = v[i - size()];
        }
        return ret;
    }
    int &operator[](int ind) const {
        return this->data[ind];
    }
    int size() const { return __size; }
    ~vector() {
        if (data) delete[] data;
        __size = 0;
    }
private:
    int __size;
    int *data;
};

} // end of haizei

class A {
public:
    A operator+(int x) {} //返回右值
    A &operator+=(int x) {} //返回左值，使用左值引用
};

ostream &operator<<(ostream &out, const haizei::vector &v) {
    for (int i = 0; i < v.size(); i++) {
        out << v[i] << " ";
    }
    return out;
}

int main() {
    haizei::vector v1, v2;
    for (int i = 0; i < v1.size(); i++) v1[i] = rand() % 100;
    for (int i = 0; i < v2.size(); i++) v2[i] = rand() % 100;
    haizei::vector v3(v1 + v2);
    cout << v1 << endl;
    cout << v2 << endl;
    cout << v3 << endl;
    haizei::vector v4(move(v1)); //强行调用移动构造
    cout << v1 << endl;
    cout << v4 << endl;
    //return 0;
    int x = 1234, y = 456;
    int &rx = x; //左值引用
    
    func(1234); //字面量一定是右值
    func(x);
    func(x + y);
    func(x++);
    func(++x);
    func(x + 123);
    func(x *= 2);
    func(y += 3);
    func(y * 3);

    return 0;
}
