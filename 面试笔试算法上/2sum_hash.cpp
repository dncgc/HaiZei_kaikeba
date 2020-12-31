/*************************************************************************
	> File Name: 2sum_hash.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 31 Dec 2020 06:50:11 PM CST
 ************************************************************************/
//man、unordered_map是键值对
#include <iostream>
#include <unordered_map>
using namespace std;

int n, target, num[100005];
unordered_map<int, int> m;

int main() {
    cin >> n >> target;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
        m[num[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        int t = target - num[i];
        //hash中是否存在t
        if (m.count(t)) {
            cout << i << "\t" << m[t] << endl;
            cout << num[i] << "\t" << t << endl;
            return 0;
        }
    }
    cout << "not find" << endl;
    return 0;
}
