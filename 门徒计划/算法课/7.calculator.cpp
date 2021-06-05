/*************************************************************************
	> File Name: 7.calculator.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 18 Mar 2021 09:25:54 PM CST
 ************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;

int calc(char *s, int l, int r) {
    int op = -1, pri = 10000 - 1, cur_pri, temp = 0;
    for (int i = l; i <= r; i++) {
        cur_pri = 10000;
        switch(s[i]) {
            case '+':
            case '-': cur_pri = 1 + temp; break;
            case '*':
            case '/': cur_pri = 2 + temp; break;
            case '(': temp += 100; break;
            case ')': temp -= 100; break;
        }
        if (cur_pri <= pri) {
            pri = cur_pri;
            op = i;
        }
    }
    if (op == -1) {
        int num = 0;
        for (int i = l; i <= r; i++) {
            if (s[i] < '0' || s[i] > '9') continue;
            num = num * 10 + (s[i] - '0');
        }
        return num;
    }
    int a = calc(s, l, op - 1);
    int b = calc(s, op + 1, r);
    switch (s[op]) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
}

int main() {
    char s[100];
    while (~scanf("%[^\n]s", s)) {
        getchar();
        printf("%s = %d\n", s, calc(s, 0, strlen(s) - 1));
    }
    return 0;
}
