/*************************************************************************
	> File Name: map.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 14 Jan 2021 07:45:28 PM CST
 ************************************************************************/

#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main() {
    //map<int, char> m;
    unordered_map<int, char> m;
    m[5] = 'A';
    m[6] = '1';
    m[3] = '*';
    if (m.count(6)) {
        cout << m[6] << endl;
    }
    if (m.count(0)) {
        cout << m[0] << endl;
    } else {
        cout << "not find key 0" << endl;
    }
    if (m[1]) {//相当于执行m[1]=0,不建议这么操作
        cout << m[1] << endl;
    } else {
        cout << "not find key 1" << endl;
    }
    return 0;
}
