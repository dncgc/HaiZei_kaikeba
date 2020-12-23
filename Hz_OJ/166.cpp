/*************************************************************************
	> File Name: 166.cpp
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon 21 Sep 2020 05:02:54 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string sa, sb;
    int ind;
    cin >> sa >> ind >> sb;
    if (sa.size() > 100) cout << 100 << endl;
    else cout << sa.size() << endl;
    sa.insert(ind - 1, sb);
    cout << sa << endl;
    cout <<sa.size() - sa.rfind("x") << endl;
    return 0;
    /*string A, B, C;//mine
    int N, len;
    cin >> A >> N >> B;
    len = (A.length() > 100 ? 100 : A.length());
    C.append(A, 0, N - 1);
    C.append(B);
    C.append(A, N - 1);
    cout << len << endl << C << endl << C.length() - C.rfind('x') << endl;
    return 0;*/
}
