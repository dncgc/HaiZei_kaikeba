/*************************************************************************
	> File Name: 577.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 15 Jan 2021 02:19:56 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <cstdio>
#include <unordered_map>
using namespace std;

int main() {
    char str[15];
    string ans = "";
    unordered_map<string, int> map;
    while (~scanf("%s", str)) {
        for (int i = 0; str[i]; i++) {
            if (str[i] >= 'A' && str[i] <= 'Z') str[i] += 32;
        }
        string s = str;
        map[s] += 1;
        if (map[s] > map[ans] || (map[s] == map[ans] && s < ans)) {
            ans = s;
        }
    }
    cout << ans << " " << map[ans] << endl;
    return 0;
}
