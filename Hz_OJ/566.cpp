/*************************************************************************
	> File Name: 566.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 15 Jan 2021 03:44:32 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n, m;
    unordered_map<string, int> umap;
    vector<vector<string> > v;
    cin >> n >> m;
    for (int i = 0, k = 0; i < m; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        if (!umap.count(s1)) {
            umap[s1] = k;
            v.push_back(vector<string>{});
            v[k].push_back(s1);
            v[k].push_back(s2);
            k++;
        } else {
            v[umap[s1]].push_back(s2);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0, k = v[i].size(); j < k; j++) {
            j && cout << " ";
            cout << v[i][j];
        }
        cout << endl;
    }

    return 0;
    /*
    int n, m;
    unordered_map<string, vector<string> > umap;
    vector<string> v;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        if (!umap.count(s1)) {
            v.push_back(s1);
        }
        umap[s1].push_back(s2);
    }
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
        for (int j = 0, k = umap[v[i]].size(); j < k; j++) {
            cout << umap[v[i]][j] << " ";
        }
        cout << endl;
    }
    return 0;
    */
}
