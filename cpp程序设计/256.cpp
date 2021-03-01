/*************************************************************************
	> File Name: 256.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon 01 Mar 2021 08:52:44 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;

class BigInt : public vector<int> {
public:
    BigInt(int);
    void operator*=(int);
    void operator/=(int);
    BigInt operator/(int);
    bool operator<(const BigInt &) const;
    bool operator>(const BigInt &) const;
private:
    void proccess_digit();
};

BigInt::BigInt(int x) {
    push_back(x);
    proccess_digit();
}

void BigInt::proccess_digit() {
    for (int i = 0; i < size(); i++) {
        if (at(i) < 10) continue;
        if (i + 1 == size()) push_back(0);
        at(i + 1) += at(i) / 10;
        at(i) %= 10;
    }
    while (size() > 1 && at(size() - 1) == 0) pop_back();
    return ;
}

void BigInt::operator*=(int x) {
    for (int i = 0; i < size(); i++) at(i) *= x;
    proccess_digit();
    return ;
}

void BigInt::operator/=(int x) {
    int y = 0;
    for (int i = size() - 1; i >= 0; i--) {
        y = y * 10 + at(i);
        at(i) = y / x;
        y %= x;
    }
    proccess_digit();
    return ;
}

BigInt BigInt::operator/(int x) {
    BigInt ret(*this);
    ret /= x;
    return ret;
}

bool BigInt::operator<(const BigInt &a) const {
    if (size() - a.size()) return size() < a.size();
    for (int i = size() - 1; i >= 0; i--) {
        if (at(i) - a[i]) return at(i) < a[i];
    }
    return false;
}

bool BigInt::operator>(const BigInt &a) const {
    return a < (*this);
}

ostream &operator<<(ostream &out, const BigInt &a) {
    for (int i = a.size() - 1; i >= 0; i--) {
        out << a[i];
    }
    return out;
}

int main() {
    vector<PII> arr;
    int n;
    cin >> n;
    for (int i = 0, a, b; i <= n; i++) {
        cin >> a >> b;
        arr.push_back(PII(a, b));
    }
    sort(arr.begin() + 1, arr.end(), 
         [](const PII &x, const PII &y) { 
            return x.first * x.second < y.first * y.second;
        }
    );
    BigInt p = arr[0].first, ans = 0;
    for (int i = 1; i <= n; i++) {
        BigInt temp = p / arr[i].second;
        ans = max(ans, temp);
        p *= arr[i].first;
    }
    cout << ans << endl;

    return 0;
}
