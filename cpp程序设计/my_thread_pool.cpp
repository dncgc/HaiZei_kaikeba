/*************************************************************************
	> File Name: my_thread_pool.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sun 21 Mar 2021 06:13:49 PM CST
 ************************************************************************/

#include <iostream>
#include <thread>
#include <functional>
#include <vector>
#include <queue>
using namespace std;

template<typename FUNCTION>
class Task {
public:
};

class thread_pool {
public:


private:
    vector<thread> t;
    queue<FUNCTION> funcq;
};

int main() {
    return 0;
}
