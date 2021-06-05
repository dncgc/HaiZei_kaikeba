/*************************************************************************
	> File Name: 22.radix_sort.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 21 May 2021 08:37:23 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

#define __high16(a) (((a) & 0xffff0000) >> 16)
#define high16(a) (__high16(a) > 32767 ? (__high16(a) - 32768) : (__high16(a) + 32768))

void radix_sort(int *arr, int n) {
    int cnt[65536] = {0};
    int *temp = (int *)malloc(sizeof(int) * n);
    // low 16 bit sort
    for (int i = 0; i < n; i++) cnt[arr[i] & 0xffff] += 1; // count
    for (int i = 1; i < 65536; i++) cnt[i] += cnt[i - 1]; // prefix sum
    for (int i = n - 1; i >= 0; --i) temp[--cnt[arr[i] & 0xffff]] = arr[i]; // placement
    //init cnt;
    for (int i = 0; i < 65536; i++) cnt[i] = 0;
    // high 16 bit sort
    for (int i = 0; i < n; i++) cnt[high16(temp[i])] += 1;
    for (int i = 1; i < 65536; i++) cnt[i] += cnt[i - 1];
    for (int i = n - 1; i >= 0; --i) arr[--cnt[high16(temp[i])]] = temp[i];
    free(temp);
    return ;
}

void output(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return ;
}

int *getRandData(int n) {
    int *temp = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) temp[i] = (rand() % 2 ? -1 : 1) * (rand() % 100);
    return temp;
}

int main() {
    #define MAX_N 20
    int *arr = getRandData(MAX_N);
    output(arr, MAX_N);
    radix_sort(arr, MAX_N);
    output(arr, MAX_N);
    return 0;
}
