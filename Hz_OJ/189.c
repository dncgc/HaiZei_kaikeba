/*************************************************************************
	> File Name: 189.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 23 Sep 2020 10:54:27 AM CST
 ************************************************************************/

#include <stdio.h>

int binary_search(int num[], int end, int k) {
    int begin = 0, mid = 0;
    end -= 1;
    while(begin <= end) {
        mid = (begin + end) >> 1;
        if (num[mid] > k) end = mid - 1;
        else if (num[mid] < k) begin = mid + 1;
        else return ++mid;
    }
    return 0;
}

int main() {
    int N, K;
    scanf("%d%d", &N, &K);
    int numn[N], numk;
    for (int i = 0; i < N; i++) {
        scanf("%d", numn + i);
    }
    for (int i = 0; i < K; i++) {
        scanf("%d", &numk);
        i && printf(" ");
        printf("%d", binary_search(numn, N, numk));
    }
    printf("\n");
    return 0;
}
