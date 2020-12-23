/*************************************************************************
	> File Name: 462.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue Oct  6 15:47:20 2020
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <inttypes.h>

struct Account {
    char type;
    char str[20];
};

int str2num(char *str) {
    int i = 0, num = 0;
    while(str[i]) {
        num = num * 10 + (str[i] - '0');
        ++i;
    }
    return num;
}

void count_print(struct Account *acc, int n) {
    int64_t sum = 0; 
    int men = 0, women = 0;
    for (int i = 0; i < n; ++i) {
        if (acc[i].type == 'q') sum += str2num(acc[i].str);
        else if (acc[i].str[strlen(acc[i].str) - 2] & 1) ++men;
        else ++women;
    }
    printf("%d %d ", men, women);
    if (n - men - women) printf("%" PRId64 "\n", sum / (n - men - women));
    else printf("%" PRId64 "\n", sum);
}

int main() {
   int n;
    scanf("%d", &n);
    struct Account acc[n];
    for (int i = 0; i < n; ++i) {
        scanf("%1s%s", &acc[i].type, acc[i].str);
    }
    count_print(acc, n);
    return 0;
}
