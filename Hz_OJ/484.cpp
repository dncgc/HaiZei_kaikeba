/*************************************************************************
	> File Name: 484.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 05 Jan 2021 10:15:25 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

char str[1005]; 
int graph[1005][30];

int main() {
    char s = 'A';
    while (~scanf("%s", str)) {
        for (int i = 0; str[i]; i++) {
            int ind = str[i] - s + 1;
            if (ind > 0 && ind < 27) {
                graph[0][ind]++;
                graph[graph[0][ind]][0] = max(graph[graph[0][ind]][0], ind);
                graph[graph[0][ind]][ind] = '*';
                graph[0][0] = max(graph[0][0], graph[0][ind]);
            }
        }
    }
    for (int i = graph[0][0]; i > 0; i--) {
        for (int j = 1; j <= graph[i][0]; j++) {
            j == 1 || printf(" ");
            if (!graph[i][j]) printf(" ");
            else printf("%c", graph[i][j]);
        }
        printf("\n");
    }
    for (int i = 0; i < 26; i++) {
        i && printf(" ");
        printf("%c", s + i);
    }
    printf("\n");
    return 0;
}
