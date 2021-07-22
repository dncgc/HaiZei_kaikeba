/*************************************************************************
	> File Name: 3.exam.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 22 Jul 2021 10:16:56 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct CMP {
    bool operator()(pair<int, int> &a, pair<int, int> &b) {
        return a.first < b.first;
    }
};

string func(string &s, vector<string> &dict) {
    vector<pair<int, int>> location;
    for (string str : dict) {
        int start = s.find(str);
        int end = start + str.size() - 1;
        location.push_back({start, end});
    }
    sort(location.begin(), location.end(), CMP());
    vector<pair<int, int>> final_location;
    int start_pre = location[0].first, end_pre = location[0].second;
    for (int i = 1; i < location.size(); i++) {
        if (location[i].first <= end_pre + 1) {
            end_pre = location[i].second;
            continue;
        }
        final_location.push_back({start_pre, end_pre});
        start_pre = location[i].first;
        end_pre = location[i].second;
    }
    final_location.push_back({start_pre, end_pre});
    cout << location.size() << " " << final_location.size() << endl;
    string ret = "";
    int location_pre = 0;
    for (auto fl : final_location) {
        ret += s.substr(location_pre, fl.first - location_pre);
        ret += "<b>";
        ret += s.substr(fl.first, fl.second - fl.first + 1);
        ret += "</b>";
        location_pre = fl.second + 1;
    }
    if (location_pre < s.size()) {
        ret += s.substr(location_pre, s.size() - location_pre);
    }
    return ret;
}

int main() {
    string s;
    cin >> s;
    vector<string> dict;
    string str;
    while (cin >> str) {
        dict.push_back(str);
    }
    cout << func(s, dict) << endl;
    return 0;
}
