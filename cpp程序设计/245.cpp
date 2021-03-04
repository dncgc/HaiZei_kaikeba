/*************************************************************************
	> File Name: 245.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 27 Feb 2021 04:54:39 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> arr;
    int n;
    cin >> n;
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        arr.push_back(a);
    }
    //sort(arr.begin(), arr.end());
    //nth_element(); //自学，将笔记发到钉钉群中
    nth_element(arr.begin(), arr.begin() + n / 2, arr.end());
    int pos = arr[n / 2], sum = 0;
    for (int i = 0; i < arr.size(); i++) {
        sum += abs(arr[i] - pos);
    }
    cout << sum << endl;
    return 0;
}
