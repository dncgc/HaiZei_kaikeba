/*************************************************************************
	> File Name: 376.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 14 Jan 2021 09:48:14 PM CST
 ************************************************************************/

#include <iostream>
#include <unordered_set>
#include <queue>
using namespace std;

int main() {
    int m, n, ans = 0;
    unordered_set<int> s;
    queue<int> que;
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        int ind;
        cin >> ind;
        if (!s.count(ind)) {
            que.push(ind);
            if (s.size() == m) {
                s.erase(que.front());
                que.pop();
            }
            s.insert(ind);
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
