/*************************************************************************
	> File Name: 207.c
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 26 Sep 2020 05:06:08 PM CST
 ************************************************************************/

#include <stdio.h>

struct Grades {
    char name[20];
    int math, chinese, english, geography;
    int max, min;
    int sum;
};
int maxscore(int a, int b, int c, int d) {
    a = a > b ? a : b;
    a = a > c ? a : c;
    return a > d ? a : d;
}

int minscore(int a, int b, int c, int d) {
    a = a < b ? a : b;
    a = a < c ? a : c;
    return a < d ? a : d;
}

void print_max(struct Grades *arr, int num) {
    int max_index = 0, m = 0;
    for (int i = 0; i < num; ++i) {
        printf("%d\n", arr[i].sum);
        if (arr[i].sum <= m) continue;
        m = arr[i].sum;
        max_index = i;
    }
    printf("%s\n", arr[max_index].name);
}

void print_max_min(struct Grades *g, int num) {
    int max = 0, min = 100;
    for (int i = 0; i < num; i++) {
        max = (g[i].max > max ? g[i].max : max);
        min = (g[i].min < min ? g[i].min : min);
    }
    printf("%d %d\n", max, min);
}

int main() {
    int N;
    scanf("%d", &N);
    struct Grades class[N];
    for (int i = 0; i < N; ++i) {
        scanf("%s", class[i].name);
        scanf("%d%d%d%d", &class[i].math, &class[i].chinese, &class[i].english, &class[i].geography);
        class[i].max = maxscore(class[i].math, class[i].chinese, class[i].english, class[i].geography);
        class[i].min = minscore(class[i].math, class[i].chinese, class[i].english, class[i].geography);
        class[i].sum = class[i].math + class[i].chinese + class[i].english + class[i].geography;
    }
    print_max(class, N);
    print_max_min(class, N);
    return 0;
}
