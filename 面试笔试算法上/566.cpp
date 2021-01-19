/*************************************************************************
	> File Name: 566.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 19 Jan 2021 06:08:13 PM CST
 ************************************************************************/

#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

struct node {
    string name;
    vector<string> v;
};

node p[1005];
int n, m, cnt;
map<string, int> ma;

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        string a, b;
        cin >> a >> b;
        if (ma.count(a)) {
            p[ma[a]].v.push_back(b);
        } else {
            cnt++;
            ma[a] = cnt;
            p[ma[a]].name = a;
            p[ma[a]].v.push_back(b);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << p[i].name << " ";
        for (int j = 0; j < p[i].v.size(); j++) {
            j && cout << " ";
            cout << p[i].v[j];
        }
        cout << endl;
    }
    return 0;
}
