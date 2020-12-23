/*************************************************************************
	> File Name: 168.cpp
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon 21 Sep 2020 05:39:19 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    string name[N];
    for (int i = 0; i < N; i++) {
        cin >> name[i];
        name[i][0] -= ((name[i][0] >= 97 && name[i][0] <= 122) ? 32 : 0);
        for (int j = 1; j < name[i].length(); j++)
            name[i][j] += ((name[i][j] >= 65 && name[i][j] <= 90) ? 32 : 0);
    }
    sort(name, name + N);
    for (int i = 0; i < N; i++) {
        cout << name[i] << endl;
    }
    return 0;
}
