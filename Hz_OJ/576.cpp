/*************************************************************************
	> File Name: 576.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 15 Jan 2021 02:44:55 PM CST
 ************************************************************************/

#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
struct Node {
    int price, num;
};

int main() {
    int n, k;
    long long ans = 0;
    unordered_map<string, Node> map;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        string s;
        int p, num;
        cin >> s >> p >> num;
        map[s] = Node{p, num};
    }
    for (int i = 1; i <= k; i++) {
        string s;
        int num;
        cin >> s >> num;
        if (num > map[s].num) {
            cout << -i << endl;
            return 0;
        } else {
            ans += num * map[s].price;
            map[s].num -= num;
        }
    }
    cout << ans << endl;
    return 0;
}
