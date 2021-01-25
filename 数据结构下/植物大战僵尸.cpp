/*************************************************************************
	> File Name: 植物大战僵尸.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon 25 Jan 2021 08:44:00 PM CST
 ************************************************************************/

#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
#define swap(a, b) {\
    __typeof(a) _a = a;\
    a = b, b = _a;\
}

#define MAX_N 50000
typedef struct Data {
    int n, f, s;
} Data;

Data heap[101][MAX_N + 5];

int gt(Data a, Data b) {
    if (a.f - b.f) return a.f > b.f;
    return a.n < b.n;
}

void push(Data *h, Data val) {
    h[++h[0].n] = val;
    int ind = h[0].n;
    while (ind / 2 && gt(h[ind], h[ind / 2])){
        swap(h[ind], h[ind / 2]);
        ind /= 2;
    }
    return ; 
}

Data top(Data *h) { return h[1]; }

void pop(Data *h) {
    swap(h[1], h[h[0].n]);
    h[0].n -= 1;
    int ind = 1, temp;
    while (ind * 2 <= h[0].n) {
        temp = ind;
        if (gt(h[ind * 2], h[temp])) temp = ind * 2;
        if (ind * 2 + 1 <= h[0].n && gt(h[ind * 2 + 1], h[temp])) temp = ind * 2 + 1;
        if (temp == ind) break;
        swap(h[temp], h[ind]);
        ind = temp;
    }
    return ;
}

int empty(Data *h) { return h[0].n == 0; }
void clear(Data *h) { h[0].n = 0; }

void init_heap() {
    for (int i = 0; i <= 100; i++) clear(heap[i]);
    return ;
}

void solve() {
    init_heap();
    int n, f, s;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &f, &s);
        Data d = {i, f, s};
        push(heap[s], d);
    }
    for (int i = 1; i <= n; i++) {
        int ind = 0, pos = 0;
        for (int j = 1; j <= 100; j++) {
            if (empty(heap[j])) continue;
            int cur_pos = (i - 1) * j + top(heap[j]).f;
            if (ind == 0) {
                ind = j, pos = cur_pos;
                continue;
            }
            if (pos < cur_pos || (pos == cur_pos && top(heap[j]).n < top(heap[ind]).n)) {
                ind = j, pos = cur_pos;
            }
        }
        if (i - 1) printf(" ");
        printf("%d", top(heap[ind]).n);
        pop(heap[ind]);
    }
    printf("\n");
    return ; 
}

int main() {
    int tcase, n = 0;
    scanf("%d", &tcase);
    while ((n++) < tcase) {
        printf("Case #%d:\n", n);
        solve();
    }
    return 0;
}
