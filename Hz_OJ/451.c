/*************************************************************************
	> File Name: 451.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon Oct  5 15:12:46 2020
 ************************************************************************/

#include <stdio.h>
/*#define swap(a, b) {\
    __typeof(a) _a = a;\
    a = b; b = _a;\
}

void sort_print(int *arr, int n) {
    int issort, lastposition;//每回合最后一次交换位置的元素下标
    int sortborder = n - 1;//记录无序数列的边界
    for (int i = 0; i < n - 1; ++i) {
        issort = 1;
        for (int j = 0; j < sortborder; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                issort = 0;
                lastposition = j;
            }
        }
        sortborder = lastposition;
        if (issort) break;
    }
    for (int i = 0; i < n; ++i) {
        printf("%d\n", arr[i]);
    }
}*/
void quicksort(int *, int, int);

int main() {
    int n;
    scanf("%d", &n);
    int price[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", price + i);
    }
    quicksort(price, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        printf("%d\n", price[i]);
    }
    return 0;
}

void quicksort(int *a, int l, int r) {
    int i = l, j = r;
    int key = a[l];
    if (l >= r) return ;
    while(l < r) {
        while (l < r && key <= a[r]) --r;
        if (key > a[r]) {
            a[l] = a[r];
            ++l;
        }
        while (l < r && key >= a[l]) ++l;
        if (key < a[l]) {
            a[r] = a[l];
            --r;
        }
    }
    a[l] = key;
    quicksort(a, i, l - 1);
    quicksort(a, l + 1, j);
}
