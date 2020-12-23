/*************************************************************************
	> File Name: 170.cpp
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon 21 Sep 2020 06:20:40 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    string str[N];
    string s = "Ban_smoking";
    int index;
    for (int i = 0; i < N; i++) {
        index = 0;
        cin >> str[i];
        while ((index = str[i].find(s, index)) != str[i].npos) {
            str[i][index] = 'N';
            str[i][index + 1] = 'o';
            str[i].erase(index + 2, 1);
            ++index;
        }
    }
    for (int i = 0; i < N; i++) {
        cout << str[i] << endl;
    }
    return 0;
}
