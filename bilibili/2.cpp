/*************************************************************************
	> File Name: 2.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 13 Oct 2021 07:40:59 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
        string nums;
        map<int, int> m;
        int cnt = 0;
    while (cin >> nums) {
                cnt += 1;
                int begin = 0;
        for (int i = 0; i < nums.size(); i++) {
                        while (nums[i] && nums[i] != ',') i++;
                        int t = atoi(nums.substr(begin, i - begin).c_str());
                        // cout << t << endl;
                        m[t] += 1;
                        begin = i + 1;
                    
        }
            
    }
    cout << cnt << endl;
    for (auto it : m) {
        if (it.second == cnt) {
                        cout << it.first << endl;
                        return 0;
                    
        }
            
    }
        cout << -1 << endl;
        return 0;

}
