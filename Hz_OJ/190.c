/*************************************************************************
	> File Name: 190.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 23 Sep 2020 11:14:10 AM CST
 ************************************************************************/

#include <stdio.h>
#include <malloc.h>

int binary_search(int *p, int begin, int end, int num) {
    int mid = 0;
    while(begin <= end) {
        mid = (begin + end) >> 1;
        if (p[mid] > num) end = mid - 1;
        else if (p[mid] < num) begin = mid + 1;
        else return 1;
    }
    return 0;
}

int xplusy(int *prime, int n, int len) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        if(binary_search(prime, i, len - 1, n - prime[i]))
            ++count;
    }
    return count;
}

int main() {
    int n;
    scanf("%d", &n);
    int *arr = (int *) calloc(n + 1, sizeof(int));
    arr[0] = arr[1] = 1;
    int count = 2;
    for (int i = 2; i * i <= n; i++) {
        for (int j = i; j <= n / i; j++) {
            if(arr[i * j] == 0) ++count;
            arr[i * j] = 1;
        }
    }
    int len = n + 1 - count;
    int *prime = (int *) calloc(len, sizeof(int));
    count = -1;
    for (int i = 2; i <= n; i++) {
        if (arr[i] == 0) prime[++count] = i;
    }
    free(arr);
    arr = NULL;
    printf("%d\n", xplusy(prime, n, len));
    free(prime);
    prime = NULL;
    return 0;
}
