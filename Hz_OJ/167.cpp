/*************************************************************************
	> File Name: 167.cpp
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon 21 Sep 2020 05:31:34 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string A, B, C;
    int N;
    cin >> A >> N >> B;
    C.append(A, 0, N - 1);
    C.append(B);
    C.append(A, N - 1, A.length());
    cout << A.length() << endl << A.find('a') + 1 << endl << C << endl;
    return 0;
}
