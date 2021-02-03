/*************************************************************************
	> File Name: 41.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 03 Feb 2021 11:08:40 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> bignum[3];

void to_bignum(int val, vector<int> &v) {
    while (val) {
        v.push_back(val % 10);
        val /= 10;
    }
    return ;
}

void mult(vector<int> &v, int kk, vector<int> &ans) {
    int temp = 0;
    for (int i = 0; i < v.size(); i++) {
        int t = kk * v[i] + temp;
        ans.push_back(t % 10);
        temp = t / 10;
    }
    while(temp) {
        ans.push_back(temp % 10);
        temp /= 10;
    }
    return ;
}

void add(vector<int> &a, vector<int> &b, vector<int> &ans) {
    int n = max(a.size(), b.size());
    int temp = 0;
    for (int i = 0; i < n; i++) {
        if (i >= a.size()) a.push_back(0);
        if (i >= b.size()) b.push_back(0);
        int t = a[i] + b[i] + temp;
        if (i >= ans.size()) ans.push_back(0);
        ans[i] = t % 10;
        temp = t / 10;
    }
    while(temp) {
        ans.push_back(temp % 10);
        temp /= 10;
    }
    return ;
}

int main() {
    scanf("%d%d", &n, &k);
    to_bignum(k, bignum[1]);
    to_bignum(k * (k - 1), bignum[2]);
    to_bignum(k * (k - 1) * (k - 2), bignum[0]);
    for (int i = 4; i <= n; i++) {
        vector<int> t1, t2;
        mult(bignum[(i - 1) % 3], k - 2, t1);
        mult(bignum[(i - 2) % 3], k - 1, t2);
        add(t1, t2, bignum[i % 3]);
    }
    for (int i = bignum[n % 3].size() - 1; i >= 0; i--) {
        printf("%d", bignum[n % 3][i]);
    }
    printf("\n");
    return 0;
}
