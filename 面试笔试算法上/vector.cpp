/*************************************************************************
	> File Name: vector.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 14 Jan 2021 06:17:04 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v1;
    for (int i = 9; i >= 5; i--) {
        v1.push_back(i);
    }
    for (int i = 1; i <= 5; i++) {
        v1.push_back(i);
    }
    for (int i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }
    vector<vector<int> > v2; //c++11 之前不加空格会解析成>>运算符
    for (int i = 0; i < 4; i++) {
        v2.push_back(vector<int>());
        for (int j = 0; j <= i; j++) {
            v2[i].push_back(j);
        }
    }
    for (int i = 0; i < v2.size(); i++) {
        for (int j = 0; j < v2[i].size(); j++) {
            cout << v2[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
