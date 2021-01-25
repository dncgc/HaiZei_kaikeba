/*************************************************************************
	> File Name: 逆波兰式.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon 25 Jan 2021 07:30:29 PM CST
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

#define INF 0x3f3f3f3f

char str[10000];

int calc(char *str, int l, int r) {
    int pos = -1, pri = INF - 1, temp = 0;
    for (int i = l; i <= r; i++) {
        int cur = INF;
        switch (str[i]) {
            case '(': temp += 100; break;
            case ')': temp -= 100; break; 
            case '+':
            case '-': cur = temp + 1; break;
            case '*':
            case '/': cur = temp + 2; break;
            case '^': cur = temp + 3; break;
        }
        if (cur <= pri) {
            pos = i, pri = cur;
        }
    }
    if (pos == -1) {
        int num = 0;
        for (int i = l; i <= r; i++) {
            if (str[i] < '0' || str[i] > '9') continue;
            num = num * 10 + str[i] - '0';
        }
        printf("%d", num);
        return num;
    }
    int a = calc(str, l, pos - 1);
    printf(" ");
    int b = calc(str, pos + 1, r);
    printf(" %c", str[pos]);
    switch (str[pos]) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '^': return (int)pow(a, b);
    }
    return 0;
}

int main() {
    while(~scanf("%[^\n]s", str)) {
        getchar();
        int val = calc(str, 0, strlen(str) - 1);
        printf("\n");
        printf("%s = %d\n", str, calc(str, 0, val));
    }
    return 0;
}
