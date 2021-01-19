/*************************************************************************
	> File Name: 573.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 19 Jan 2021 10:57:05 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int qnum, period, t;
    bool operator< (const Node &a) const {
        if (this->period == a.period) return this->qnum > a.qnum;
        return this->period > a.period;
    }
};
priority_queue<Node> pq;

char str[10];
int k, qn, per;

int main() {
    while(scanf("%s", str)) {
        if (str[0] == '#') break;
        scanf("%d%d", &qn, &per);
        pq.push(Node{qn, per, per});
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        Node temp = pq.top();
        printf("%d\n", temp.qnum);
        pq.pop();
        pq.push(Node{temp.qnum, temp.period + temp.t, temp.t});
    }
        
    return 0;
}
