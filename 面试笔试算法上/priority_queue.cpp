/*************************************************************************
	> File Name: priority_queue.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 14 Jan 2021 07:12:31 PM CST
 ************************************************************************/

#include <iostream>
#include <queue>
using namespace std;

struct node{
    int a, b;
    bool operator< (const node &nodea) const {//硬性要求重载小于号
        return this->a > nodea.a;
    }
};

int main() {
    priority_queue<node> que;
    que.push((node){5, 6});
    que.push((node){3, 8});
    que.push((node){4, 7});
    while (!que.empty()) {
        node temp = que.top();
        que.pop();
        cout << temp.a << " " << temp.b << endl;
    }
    /*
    //priority_queue<int> q1; //默认大顶堆
    priority_queue<int, vector<int>, greater<int> > q1;
    q1.push(5);
    q1.push(3);
    q1.push(9);
    q1.push(8);
    while (!q1.empty()) {
        cout << q1.top() << endl;
        q1.pop();
    }
    */
    return 0;
}
