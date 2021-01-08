/*************************************************************************
	> File Name: 516.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 08 Jan 2021 08:40:41 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int n, numc[100005], ans, numw;
char s[100005];

int main() {
    cin >> n >> &s[1];
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'C') {
            numc[i] = numc[i - 1] + 1;
        } else {
            numc[i] = numc[i - 1];
        }
    }
    for (int i = n; i > 0; i--) {
        if (s[i] == 'W') {
            numw++;
        } else if (s[i] == 'O') {
            ans += numc[i] * numw;
        }
    }
    cout << ans << endl;
    return 0;
}
