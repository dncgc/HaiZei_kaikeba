/*************************************************************************
	> File Name: 20.merge_sort.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 14 May 2021 07:16:47 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

void merge_sort(int *arr, int l, int r) {
    if (l >= r) return ;
    int mid = (l + r) >> 1;
    merge_sort(arr, l, mid); // left
    merge_sort(arr, mid + 1, r); // right
    int *temp = (int *)malloc(sizeof(int) * (r - l + 1));
    int k = 0, p1 = l, p2 = mid + 1;
    while(p1 <= mid || p2 <= r) {
        if ((p2 > r) || (p1 <= mid && arr[p1] <= arr[p2])) {
            temp[k++] = arr[p1++];
        } else {
            temp[k++] = arr[p2++];
        }
    }
    for (int i = l; i <= r; i++) arr[i] = temp[i - l];
    free(temp);
    return ;
}

int main() {
    int n;
    int arr[100];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    merge_sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
