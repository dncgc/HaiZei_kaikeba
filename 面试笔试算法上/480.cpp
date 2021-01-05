/*************************************************************************
	> File Name: 480.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 05 Jan 2021 08:29:21 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

struct node {
    char s[4];
    int num1, num2, flag;//flag = 2: / 
};

node bl[15];

int main() {
    for (int i = 0; cin >> bl[i].s; i++) {
        if (bl[i].s[0] == '/') {
            bl[i].num1 = 10;
            bl[i].num2 = 10;
            bl[i].flag = 2;
        } else if (bl[i].s[1] == '/') {
            bl[i].num1 = bl[i].s[0] - '0';
            bl[i].num2 = 10;
            bl[i].flag = 1;
        } else {
            bl[i].num1 = bl[i].s[0] - '0';
            bl[i].num2 = bl[i].s[1] - '0' + bl[i].num1;
        }
    }
    int ans = 0;
    for (int i = 0; i < 10; i++) {
        ans += bl[i].num2;
        if (bl[i].flag == 1) {
            ans += bl[i + 1].num1;
        } else if (bl[i].flag == 2) {
            if (bl[i + 1].flag == 2) {
                ans += 10 + bl[i + 2].num1;
            } else {
                ans += bl[i + 1].num2;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
