/*************************************************************************
	> File Name: 10.quick_sort.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 27 Nov 2020 02:15:44 PM CST
 ************************************************************************/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define max_n 10000

#define swap(a, b) {\
    __typeof(a) _a = a;\
    a = b; b = _a;\
}

/*void quick_sort(int *num, int l, int r) {
    while (l < r) {
        int x = l, y = r, z = num[(l + r) >> 1];
        do {
            while (x <= y && num[x] < z) x++;
            while (x <= y && num[y] > z) y--;
            if (x <= y) {
                swap(num[x], num[y]);
                x++, y--;
            }
        } while (x <= y);
        quick_sort(num, x, r);
        r = y;
    }
    return ; 
}*/

void quick_sort(int *num, int l, int r) {
    if (l >= r) return ;
    int x = l, y = r, z = num[(l + r) >> 1];
    while (x <= y) {
        while (x <= y && num[y] > z) --y;
        while(x <= y && num[x] < z) ++x;
        if (x <= y) {
            swap(num[x], num[y]);
            x++, y--;
        }
    }
    quick_sort(num, l, y);
    quick_sort(num, x, r);
    return ; 
}

int arr[max_n + 5];

void randint(int *num, int n) {
    while (n--) num[n] = rand() % 100;
    return ;
}

void output(int *num, int n) {
    printf("arr = [");
    for (int i = 0; i < n; i++) {
        i && printf(" ");
        printf("%d", num[i]);
    }
    printf("]\n");
    return ;
}

int main() {
    srand(time(0));
    randint(arr, max_n);
    output(arr, max_n);
    quick_sort(arr, 0, max_n - 1);
    output(arr, max_n);
    return 0;
}
