/*************************************************************************
	> File Name: next_permutation.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 19 Jan 2021 08:36:09 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> v;

void p() {
    for (int i = 0; i < n; i++) {
        i && cout << " ";
        cout << v[i];
    }
    cout << endl;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        v.push_back(i);
    }
    do {
        p();
    } while (next_permutation(v.begin(), v.end()));
    return 0;
}
