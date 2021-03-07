/*************************************************************************
	> File Name: 49.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sun 07 Mar 2021 10:26:52 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int n, vall, ind = 1, v[20005], w[20005], ans[100005];
int bit2[25];

void init() {
    int t = 1;
    for (int i = 0; i < 21; i++) {
        bit2[i] = t;
        t *= 2;
    }
}

int main() {
    init();
    cin >> vall >> n;
    for (int i = 1; i <= n; i++) {
        int a, b, c, cnt = 0;
        cin >> a >> b >> c;
        while (c) {
            if (c > bit2[cnt]) {
                v[ind] = a * bit2[cnt];
                w[ind] = b * bit2[cnt];
                c -= bit2[cnt];
                cnt++;
            } else {
                v[ind] = a * c;
                w[ind] = b * c;
                c = 0;
            }
            ind++;
        }
    }
    for (int i = 1; i <= ind; i++) {
        for (int j = vall; j >= v[i]; j--) {
            ans[j] = max(ans[j], ans[j - v[i]] + w[i]);
        }
    }
    cout << ans[vall] << endl;
    return 0;
}
