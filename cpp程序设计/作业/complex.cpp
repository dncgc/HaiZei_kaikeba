/*************************************************************************
	> File Name: complex.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 05 Mar 2021 09:46:14 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class Complex {
public:
    Complex(int a, int b) : r(a), i(b) {}

    Complex &operator+=(const Complex &);
    Complex operator+(const Complex &);
    Complex &operator+=(const int);
    Complex operator+(const int);
    Complex &operator+=(const double);
    Complex operator+(const double);
    
    Complex &operator-=(const Complex &);
    Complex operator-(const Complex &);
    Complex &operator-=(const int);
    Complex operator-(const int);
    Complex &operator-=(const double);
    Complex operator-(const double);

    Complex &operator*=(const Complex &);
    Complex operator*(const Complex &);
    Complex &operator*=(const int);
    Complex operator*(const int);
    Complex &operator*=(const double);
    Complex operator*(const double);

    Complex &operator/=(const Complex &);
    Complex operator/(const Complex &);
    Complex &operator/=(const int);
    Complex operator/(const int);
    Complex &operator/=(const double);
    Complex operator/(const double);

private:
    friend ostream &operator<<(ostream &out, const Complex &);
    double r, i;
};

Complex &Complex::operator+=(const Complex &a) {
    this->r += a.r;
    this->i += a.i;
    return *this;
}

Complex Complex::operator+(const Complex &a) {
    Complex temp = *this;
    return temp += a;
}

Complex &Complex::operator+=(const int a) {
    this->r += a;
    return *this;
}

Complex Complex::operator+(const int a) {
    Complex temp = *this;
    return temp += a;
}

Complex &Complex::operator+=(const double a) {
    this->r += a;
    return *this;
}

Complex Complex::operator+(const double a) {
    Complex temp = *this;
    return temp += a;
}

Complex &Complex::operator-=(const Complex &a) {
    this->r -= a.r;
    this->i -= a.i;
    return *this;
}

Complex Complex::operator-(const Complex &a) {
    Complex temp = *this;
    return *this -= a;
}

Complex &Complex::operator-=(const int a) {
    return *this += -a;
}

Complex Complex::operator-(const int a) {
    Complex temp = *this;
    return temp += -a;
}

Complex &Complex::operator-=(const double a) {
    return *this += -a;
}

Complex Complex::operator-(const double a) {
    Complex temp = *this;
    return temp += -a;
}

Complex &Complex::operator*=(const Complex &a) {
    double r = this->r;
    this->r = r * a.r - this->i * a.i;
    this->i = r * a.i + this->i * a.r;
    return *this;
}

Complex Complex::operator*(const Complex &a) {
    Complex temp = *this;
    return temp *= a;
}

Complex &Complex::operator*=(const int a) {
    this->r *= a;
    this->i *= a;
    return *this;
}

Complex Complex::operator*(const int a) {
    Complex temp = *this;
    return temp *= a;
}

Complex &Complex::operator*=(const double a) {
    this->r *= a;
    this->i *= a;
    return *this;
}

Complex Complex::operator*(const double a) {
    Complex temp = *this;
    return temp *= a;
}

Complex &Complex::operator/=(const Complex &a) {
    if (a.r != 0 || a.i != 0) {
        Complex b(a.r, -a.i);
        Complex t = b * a;
        *this *= b;
        return *this /= t.r;
    }
    cerr << "divisor cannot be 0!" << endl;
    return *this;
}

Complex Complex::operator/(const Complex &a) {
    Complex temp = *this;
    return temp /= a;
}

Complex &Complex::operator/=(const int a) {
    if (a) {
        this->r /= a;
        this->i /= a;
        return *this;
    }
    cerr << "divisor cannot be 0!" << endl;
    return *this;
}

Complex Complex::operator/(const int a) {
    Complex temp = *this;
    return temp /= a;
}

Complex &Complex::operator/=(const double a) {
    if (a) {
        this->r /= a;
        this->i /= a;
        return *this;
    }
    cerr << "divisor cannot be 0!" << endl;
    return *this;
}

Complex Complex::operator/(const double a) {
    Complex temp = *this;
    return temp /= a;
}

ostream &operator<<(ostream &out, const Complex &c) {
    if (c.r == 0) {
        if (c.i == 0) cout << 0;
        else out << c.i << "i";
    } else {
        out << c.r;
        if (c.i > 0) out << "+";
        if (c.i == 0) return out;
        out << c.i << "i";
    }
    return out;
}

int main() {
    Complex a(1, -3);
    Complex b(2, 4);
    a += b;
    cout << a << endl;
    cout << a + b << endl;
    cout << a << endl;
    cout << a - 3 << endl;
    a -= 3.1;
    cout << a << endl;
    cout << b << endl;
    cout << a * b << endl;
    a *= b;
    cout << a << endl;
    cout << a / 0 << endl;
    cout << a / b << endl;
    return 0;
}
