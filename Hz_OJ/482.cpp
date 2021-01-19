/*************************************************************************
	> File Name: 482.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 19 Jan 2021 11:17:36 PM CST
 ************************************************************************/

#include <iostream>
#include <stack>
using namespace std;

stack<char> sl, sr;
int n;
char str[100005];

int main() {
    scanf("%s", str);
    for (int i = 0; str[i]; i++) {
        sl.push(str[i]);
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char op[10], ch[10];
        scanf("%s", op);
        switch(op[0]) {
            case 'L': {
                if (!sl.size()) break;
                sr.push(sl.top());
                sl.pop();
            } break;
            case 'D': {
                if (!sr.size()) break;
                sl.push(sr.top());
                sr.pop();
            } break;
            case 'B': {
                if (!sl.size()) break;
                sl.pop();
            } break;
            case 'P': {
                scanf("%s", ch);
                sl.push(ch[0]);
            } break;
        }
    }
    while(sl.size()) {
        sr.push(sl.top());
        sl.pop();
    }
    while(sr.size()) {
        printf("%c", sr.top());
        sr.pop();
    }
    printf("\n");
    return 0;
}
