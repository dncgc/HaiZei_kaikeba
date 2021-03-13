/*************************************************************************
	> File Name: 27.print.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 13 Mar 2021 09:03:22 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

class PRINT {
public:
    template<typename T>
    PRINT &operator()(T a) {
        cout << a << endl;
        return *this;
    }
};

int main() {
    PRINT print;
    print(123)("hello world")("hello haizei")(456)(789);
    return 0;
}
