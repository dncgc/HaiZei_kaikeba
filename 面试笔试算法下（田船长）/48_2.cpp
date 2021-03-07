/*************************************************************************
	> File Name: 48_2.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sun 07 Mar 2021 11:45:22 AM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int n, vall, v[10005], w[10005], ans[10005];

int main() {
    cin >> n >> vall;
    for(int i = 1; i <= n; i++) {
        cin >> v[i] >> w[i];
    }
    for(int i = 1; i <= n; i++) {
        for (int j = v[i]; j <= vall; j++) {
            ans[j] = max(ans[j], ans[j - v[i]] + w[i]);
        }
    }
    cout << ans[vall] << endl;
    return 0;
}
