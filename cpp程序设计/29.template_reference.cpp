/*************************************************************************
	> File Name: 29.template_reference.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sun 14 Mar 2021 02:40:28 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

namespace haizei {

template<typename T>
void swap(T &&a, T &&b) {  //模板中 T && 不是右值引用,而是告诉编译器要传入引用参数
    typename remove_reference<T> ::type c;  //将T解调引用，auto也可解掉
    c = a; a = b; b = c;
    return ;
}

}// end of haizei

int main() {
    int n = 123, m = 456;
    haizei::swap(n, m);
    cout << n << " " << m << endl;
    // haizei::swap(789, n);
    return 0;
}
