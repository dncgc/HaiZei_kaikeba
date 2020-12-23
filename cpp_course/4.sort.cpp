/*************************************************************************
	> File Name: 4.sort.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 18 Dec 2020 09:16:46 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int arr[1000];

void output(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return ;
}

bool cmp(int a, int b) {//传入两个待排序元素类型的元素，
    return a > b;//a > b时a排到b前面
}

struct CMP {
    int operator()(int a, int b) {
        return a > b;
    }
};

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    output(arr, n);
    sort(arr, arr + n, cmp);
    output(arr, n);
    sort(arr, arr + n, CMP());//CMP为可调用对象
    output(arr, n);
    sort(arr, arr + n, [](int a, int b) { return  a > b; });
    output(arr, n);
    sort(arr, arr + n, greater<int>());//从大到小排
    output(arr ,n);
    sort(arr, arr + n, less<int>());//从小到大排
    output(arr, n);
    return 0;
}
