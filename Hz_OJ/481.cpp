/*************************************************************************
	> File Name: 481.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 05 Jan 2021 11:02:28 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int r, score[2][10], ratio[15][2];

void func(int min, int win, int times) {
    for (int i = 0; i < 8; i++) {
        if (score[win][i] <= r && score[win][i] < min) {
            ratio[times + 1][win]++;
        }
    }
    return ;
}

void output(int times) {
    for (int i = 1; i <= times; i++) {
        printf("%d:%d\n", ratio[i][0], ratio[i][1]);
        ratio[0][0] += ratio[i][0];
        ratio[0][1] += ratio[i][1];
    }
    printf("%d:%d\n", ratio[0][0], ratio[0][1]);
    return ;
}

int main() {
    scanf("%d", &r);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 2; j++) {
            int min1 = 1005, min2 = 1005;
            for (int k = 0; k < 8; k++) {
                scanf("%d", &score[j][k]);
                if (score[j][k] == -1) {
                    output(i);
                    return 0;
                }
                min1 = min(min1, score[0][k]);
                min2 = min(min2, score[1][k]);
            }
            if (j) {
                if (min1 < min2) {
                    func(min2, 0, i);
                } else if (min1 > min2) {
                    func(min1, 1, i);
                }
            }
        }
    }
    output(10);
    return 0;
}
