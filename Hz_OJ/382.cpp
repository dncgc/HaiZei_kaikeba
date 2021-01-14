/*************************************************************************
	> File Name: 382.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 13 Jan 2021 11:49:51 PM CST
 ************************************************************************/

#include <iostream>
#include <list>
using namespace std;
#define MAX_N 1000
#define Update(it) {\
    it++;\
    if (it == l.end()) it++;\
}
list<int> l;
int n, m;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) l.push_back(i);
    int cnt = 0;
    auto it = l.begin();
    while (l.size() > 1) {
        ++cnt;
        if (cnt % m == 0) {
            auto del = it;
            Update(it);
            l.erase(del);
        } else {
            Update(it);
        }
    }
    cout << l.front() << endl;
    return 0;
}
