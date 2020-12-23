/*************************************************************************
	> File Name: euler8.c
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 23 Dec 2020 08:06:55 PM CST
 ************************************************************************/

#include <stdio.h>

char num[1005];

int main() {
    long long ans = 0, cnt = 0, result = 1;
    scanf("%s", num);
    for (int i = 0; i < 1000; i++) {
        if (i < 13) {
            result *= num[i] - '0';
        } else {
            if (num[i] == '0') {
                cnt++;
            } else {
                result *= num[i] - '0';
            }
            if (num[i - 13] == '0') {
                cnt--;
            } else {
                result /= num[i - 13] - '0';
            }
        }
        if (cnt == 0) {
            ans = ans < result ? result : ans;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
