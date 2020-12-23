/*************************************************************************
	> File Name: 2.strlen.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 18 Dec 2020 08:08:00 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

int main() {
    string s = "0";
    for (int i = 0; i < 10000; i++) {
        s += "0";
    }
    cout << clock() << endl;
    for (int i = 0; i < 50000; strlen(s.c_str()), i++);
    cout << clock() << endl;
    for (int i = 0; i < 50000; s.length(), i++);
    cout << clock() << endl;
    s = "hello kaikeba";
    //for (int i = 0, I = strlen(s.c_str()); i < I; i++) {
    for (int i = 0; s[i]; i++) {    
        cout << s[i] << endl;
    }
    return 0;
}
