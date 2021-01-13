/*************************************************************************
	> File Name: HZOJ275.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 13 Jan 2021 06:58:59 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;
#define MAX_N 1000000
#define P 10007
#define P1 9973
#define base 13
#define base1 103
int H[MAX_N + 5];
int H1[MAX_N + 5];
int K[MAX_N + 5];
int K1[MAX_N + 5];
int inv[P];
int inv1[P1];
char s[MAX_N + 5];

void init() {
    inv[1] = 1;
    inv1[1] = 1;
    for (int i = 2; i < P; i++) {
        inv[i] = ((-(P / i) * inv[P % i]) % P + P) % P;
    }
    for (int i = 2; i < P1; i++) {
        inv1[i] = ((-(P1 / i) * inv1[P1 % i]) % P1 + P1) % P1;
    }
    K[0] = 1;
    K1[0] = 1;
    for (int i = 1; i <= MAX_N; i++) {
        K[i] = (K[i - 1] * base) % P;
        K1[i] = (K1[i - 1] * base1) % P1;
    }
    H[0] = 0;
    H1[0] = 0;
    for (int i = 1; s[i]; i++) {
        H[i] = (H[i - 1] + K[i] * s[i]) % P;
        H1[i] = (H1[i - 1] + K1[i] * s[i]) % P1;
    }
    return ;
}

int getH(int l, int r) {
    return ((H[r] - H[l - 1]) % P * inv[K[l]] % P + P) % P;
}

int getH1(int l, int r) {
    return ((H1[r] - H1[l - 1]) % P1 * inv1[K1[l]] % P1 + P1) % P1;
}
/*
int isSame(int i, int j, int n) {
    for (int k = 0; k < n; k++) {
        if (s[i + k] - s[j + k]) return false;
    }
    return true;
}
*/
int main() {
    scanf("%s", s + 1);
    int m, l1, l2, r1, r2;
    init();
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
        int val1 = getH(l1, r1);
        int val2 = getH(l2, r2);
        int val3 = getH1(l1, r1);
        int val4 = getH1(l2, r2);
        int n1 = r1 - l1 + 1, n2 = r2 - l2 + 1;
        /*
        if (n1 - n2 || val1 - val2) {
            printf("No\n");
        } else {
            if (isSame(l1, l2, n1)) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
        */
        if (n1 == n2 && val1 == val2 && val3 == val4) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
