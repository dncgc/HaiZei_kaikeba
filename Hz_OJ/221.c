/*************************************************************************
	> File Name: 221.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 02 Oct 2020 02:39:39 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int *count(int *, int *, int, int);
void QuickSort(int *, int, int);
int binary_search(int *, int, int);

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    int a[n], aa[n], h[m];
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
        aa[i] = a[i];
    }
    for (int i = 0; i < m; ++i) scanf("%d", h + i);
    int *cnt = count(aa, h, n, m);
    for (int i = 0; i < n; ++i) printf("%d\n", cnt[binary_search(aa, a[i], n - 1)]);
    return 0;
}

void QuickSort(int *a, int l, int r) {
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
    QuickSort(a, i, l - 1);
    QuickSort(a, l + 1, j);
}

int *count(int *aa, int *h, int n, int m) {
    int *cnt = (int *)calloc(n, sizeof(int));
    QuickSort(aa, 0, n - 1);
    QuickSort(h, 0, m - 1);
    int j = 0;
    for (int i = 0; i < m; ++i) {
        if (h[i] <= aa[j]) ++cnt[j];
        else {
            ++j;
            --i;
        }
        if (j >= n) break;
    }
    return cnt;
}

int binary_search(int *a, int num, int n) {
    int l = 0, mid;
    while (l <= n) {
        mid = (l + n) >> 1;
        if (a[mid] > num) n = mid - 1;
        else if (a[mid] < num) l = mid + 1;
        else return mid;
    }
}
