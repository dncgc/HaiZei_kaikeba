/*************************************************************************
	> File Name: 2.exam.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon 19 Jul 2021 04:26:03 PM CST
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maximumSwap(int num) {
    vector<int> arr1, arr2;
    while (num) {
        int t = num % 10;
        arr1.push_back(t);
        arr2.push_back(t);
        num /= 10;
    }
    sort(arr1.begin(), arr1.end());
    int n = arr1.size();
    for (int i = n - 1; i >= 0; i--) {
        if (arr1[i] == arr2[i]) continue;
        int ind = 0;
        for (int j = 0; j < n; j++) {
            if (arr2[j] == arr1[i]) {
                ind = j;
                break;
            }
        }
        swap(arr2[i], arr2[ind]);
        break;
    }
    int ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        ans = arr * 10 + arr2[i];
    }
    return ans;
}
