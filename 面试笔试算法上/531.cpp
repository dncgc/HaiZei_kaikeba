/*************************************************************************
	> File Name: 531.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 28 Jan 2021 07:44:30 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

struct node {
    int status, step;
};
int n, bit2[25], num[25], check[3000000], start;

void init() {
    bit2[0] = 1;
    for (int i = 1; i <= 20; i++) {
        bit2[i] = bit2[i - 1] * 2;
    }
    return ;
}

int main() {
    init();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            start += bit2[i];
        }
    }
    for (int i = 1; i <= n; i++) {
        int cnt, t;
        cin >> cnt;
        for (int j = 0; j < cnt; j++) {
            cin >> t;
            num[i] += bit2[t];
        }
    }
    queue<node> que;
    que.push((node){start, 0});
    check[start] = 1;
    while (!que.empty()) {
        node temp = que.front();
        que.pop();
        if (temp.status == 8) {
            cout << temp.step << endl; //终点
            return 0;
        }
        for (int i = 1; i <= n; i++) { //按 原20
            if ((temp.status & bit2[i]) == 0) { //可以按
                int t = temp.status + bit2[i]; //按下去的值
                t &= ~num[i]; //弹出来的值
                if (check[t] == 0) {
                    check[t] = 1;
                    que.push((node){t, temp.step + 1});
                }
            }
        }
    }
    return 0;
}
