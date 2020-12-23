/*************************************************************************
	> File Name: 245.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 18 Dec 2020 08:52:43 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX_N 100000
int arr[MAX_N + 5];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    nth_element(arr, arr + (n / 2), arr + n);
    int p = arr[n / 2], sum = 0;
    for (int i = 0; i < n; i++) {
        sum += abs(arr[i] - p);
    }
    cout << sum << endl;
    return 0;
    /*vector<int> arr;
    int n, a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    int p = arr[n / 2], sum = 0;
    for (int i = 0; i < n; i++) {
        sum += abs(arr[i] - p);
    }
    cout << sum << endl;
    return 0;*/
}
