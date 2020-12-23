/*************************************************************************
	> File Name: 18.heap_sort.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 05 Dec 2020 12:27:50 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define swap(a, b) {\
    __typeof(a) _a = a;\
    a = b; b = _a;\
}


void downUpdate(int *arr, int n, int ind) {
    while ((ind << 1) <= n) {
        int temp = ind, l = ind << 1, r = ind << 1 | 1;
        if (arr[l] > arr[temp]) temp = l;
        if (r <= n && arr[r] > arr[temp]) temp = r;
        if (temp == ind) break;
        swap(arr[temp], arr[ind]);
        ind = temp;
    }
    return ;
}

void heap_sort(int *arr, int n) {
    arr -= 1;
    for (int i = n >> 1; i >= 1; i--) {
        downUpdate(arr, n, i);
    }
    for (int i = n; i > 1; i--) {
        swap(arr[i], arr[1]);
        downUpdate(arr, i - 1, 1);
    }
    return ;
}

void output(int *arr, int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        i && printf(" ");
        printf("%d", arr[i]);
    }
    printf("]\n");
    return ;
}

int main() {
    srand(time(0));
    #define max_n 20
    int *arr = (int *)malloc(sizeof(int) * max_n);
    for (int i = 0; i < max_n; i++) {
        arr[i] = rand() % 100;
    }
    output(arr, max_n);
    heap_sort(arr, max_n);
    output(arr, max_n);
    free(arr);
    return 0;
}
