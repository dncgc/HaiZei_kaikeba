/*************************************************************************
	> File Name: 169.cpp
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon 21 Sep 2020 06:09:42 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    char letter[N];
    int num[N];
    int l = 0, n = 0, password = 0;
    string str;
    for (int i = 0; i < 2 * N; i++) {
        if (i & 1) cin >> num[n++];
        else cin >> letter[l++];
    }
    cin >> str;
    for (int i = 0; i < N; i++) {
        password += count(str.begin(), str.end(), letter[i]) * num[i];
    }
    cout << password << endl;
    return 0;
}
