/*************************************************************************
	> File Name: 19.quick_sort.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon 10 May 2021 10:44:17 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

void quick_sort_v1(int *arr, int l, int r) {
    if (l >= r) return ;

    int x = l, y = r, base = arr[l];
    while(x < y) {
        while (x < y && arr[y] >= base) y--;
        if (x < y) arr[x++] = arr[y];
        while (x < y && arr[x] < base) x++;
        if (x < y) arr[y--] = arr[x];
    }
    arr[x] = base;
    quick_sort_v1(arr, l, x - 1);
    quick_sort_v1(arr, x + 1, r);

    return ;
}

void quick_sort_v2(int *arr, int l, int r) {
    while (l < r) {
        int x = l, y = r, base = arr[l];
        while(x < y) {
            while (x < y && arr[y] >= base) y--;
            if (x < y) arr[x++] = arr[y];
            while (x < y && arr[x] < base) x++;
            if (x < y) arr[y--] = arr[x];
        }
        arr[x] = base;
        quick_sort_v2(arr, x + 1, r);
        r = x - 1;
    }
    return ;
}

const int threshold = 16;
inline int getmid(int a, int b, int c) {
    if (a > b) swap(a, b);
    if (a > c) swap(a, c);
    if (b > c) swap(b, c);
    return b;
}

void __quick_sort_v3(int *arr, int l, int r) {
    while (r - l > threshold) {
        int x = l, y = r, base = getmid(arr[l], arr[(l + r) / 2], arr[r]);
        do {
            while (arr[x] < base) x++;
            while (arr[y] > base) y--;
            if (x <= y) {
                swap(arr[x], arr[y]);
                x++, y--;
            }
        } while (x <= y);
        __quick_sort_v3(arr, x, r);
        r = y;
    }
    return ;
}

void final_insert_sort(int *arr, int l, int r) {
    int ind = l;
    for (int i = l + 1; i <= r; i++) {
        if (arr[i] < arr[ind]) ind = i;
    }
    while (ind > l) {
        swap(arr[ind], arr[ind - 1]);
        ind--;
    }
    for (int i = l + 2; i <= r; i++) {
        int j = i;
        while (arr[j] < arr[j - 1]) {
            swap(arr[j], arr[j - 1]);
            j--;
        }
    }

    return ;
}

void quick_sort_v3(int *arr, int l, int r) {
    __quick_sort_v3(arr, l, r);
    final_insert_sort(arr, l, r);
    return ;
}

int main() {
    int arr[10] = {3, 1, 4, 5, 9, 10};
    quick_sort_v1(arr, 0, 6);

    for (int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
