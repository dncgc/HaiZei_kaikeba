/*************************************************************************
	> File Name: 381.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 30 Dec 2020 04:06:04 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct stu {
    string name;
    int ind, money, ave, cla, paper;
    char stud, west;
};
stu st[105];

int reward(stu &s) {
    int ans = 0;
    /*
    if (s.ave > 80 && s.paper > 0) ans += 8000;
    if (s.ave > 85 && s.cla > 80) ans += 4000;
    if (s.ave > 90) ans += 2000;
    if (s.ave > 85 && s.west == 'Y') ans += 1000;
    if (s.cla > 80 && s.stud == 'Y') ans += 850;
    */
    ans =  (s.ave > 80 && s.paper > 0) ? ans + 8000 : ans;
    ans = (s.ave > 85 && s.cla > 80) ? ans += 4000 : ans;
    ans = (s.ave > 90) ? ans += 2000 : ans;
    ans = (s.ave > 85 && s.west == 'Y') ? ans += 1000 : ans;
    ans = (s.cla > 80 && s.stud == 'Y') ? ans += 850 : ans;
    return ans;
}

int main() {
    int n, ans = 0, ind = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> st[i].name >> st[i].ave >> st[i].cla >> st[i].stud >> st[i].west >> st[i].paper;
        st[i].ind = i;
        st[i].money = reward(st[i]);
        ans += st[i].money;
        ind = st[i].money > st[ind].money ? i : ind;
    }
    cout << st[ind].name << endl << st[ind].money << endl << ans << endl;
    return 0;
}
