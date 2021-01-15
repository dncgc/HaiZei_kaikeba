/*************************************************************************
	> File Name: 569.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 14 Jan 2021 11:27:03 AM CST
 ************************************************************************/

#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;
#define MAX_N 10000
struct Node {
    int v;
    double c;
};
stack<Node> s;
int n;

int main() {
    Node node;
    scanf("%d%lf%d", &node.v, &node.c, &n);
    s.push(node);
    int v;
    double c;
    char op[10];
    for (int i = 0; i < n; i++) {
        scanf("%s", op);
        switch (op[0]) {
            case 'P': {
                scanf("%d%lf", &v, &c);
                node = s.top();
                node.c = (node.v * node.c + v * c) / (node.v + v);
                node.v += v;
                s.push(node);
                printf("%d %.5lf\n", node.v, node.c);
            } break;
            case 'Z': {
                if (s.size() > 1) s.pop();
                node = s.top();
                printf("%d %.5lf\n", node.v, node.c);
            } break;
        }
    }
    return 0;
}
