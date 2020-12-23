/*************************************************************************
	> File Name: 460.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon Oct  5 18:21:45 2020
 ************************************************************************/

#include <stdio.h>

int last_number(int *arr, int n, int k) {
    int index = -1, number = n;
    while(number--) {
        int kk = k;
        while(kk--) {
            ++index;
            if (index == n) index = 0;
            while(arr[index] == -1) {
                ++index;
                if (index == n) index = 0;
            }
        }
        if (number == 0) return arr[index];
        arr[index] = -1;
    }
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int num[n];
    for (int i = 0; i < n; ++i) {
        num[i] = i + 1;
    }
    printf("%d\n", last_number(num, n, k));
    return 0;
}
