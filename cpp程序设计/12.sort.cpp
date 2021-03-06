/*************************************************************************
	> File Name: 12.sort.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 06 Mar 2021 04:34:23 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

ostream &operator<<(ostream &out, const vector<int> &a) {
    for (auto x : a) {
        out << x << " ";
    }
    return out;
}

bool cmp1(int a, int b) {
    return a > b;
}

class CMP {
public:
    CMP(int z = 0) : z(z) {} // z = 0 less,  z = 1 greater
    bool operator()(int a, int b) {
        return (a < b) ^ !!(z);
    }
    int z;
};

namespace haizei {
//由function定义的 可以代表函数、函数指针对象甚至lambda表达式
void sort(int *arr, int l, int r, function<bool(int, int)> cmp = CMP()) {
    if (l >= r) return ;
    int x = l, y = r, z = arr[(l + r) >> 1];
    do {
        while (cmp(arr[x], z)) ++x;
        while (cmp(z, arr[y])) --y;
        if (x <= y) {
            swap(arr[x], arr[y]);
            ++x, --y;
        }
    } while (x <= y);
    sort(arr, l, y, cmp);
    sort(arr, x, r, cmp);
    return ;
}
} // end of haizei;

int main() {
    vector<int> arr;
    int n;
    cin >> n;
    while (n--) { int a; cin >> a, arr.push_back(a); }
    CMP cmp2;
    sort(arr.begin(), arr.end(), CMP()); //传入一个匿名对象，即一个仿函数, 也可直接传入cmp2
    cout << arr << endl;
    int arr2[5] = {6, 8, 4, 5, 1};
    haizei::sort(arr2, 0, 4);
    for (int i = 0; i < 5; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    
    haizei::sort(arr2, 0, 4, cmp1);
    for (int i = 0; i < 5; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    haizei::sort(arr2, 0, 4);
    for (int i = 0; i < 5; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;

    haizei::sort(arr2, 0, 4, CMP(2));
    for (int i = 0; i < 5; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}
