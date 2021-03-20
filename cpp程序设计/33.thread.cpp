/*************************************************************************
	> File Name: 33.thread.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 20 Mar 2021 07:37:31 PM CST
 ************************************************************************/

#include <iostream>
#include <thread>
#include <functional>
using namespace std;

void func(int x) {
    for (int i = 0; i < x; i++) cout << i << endl;
    return ;
}

void add_one(int &x) {
    cout << "add_one function" << endl;
    x += 1;
    return ;
}

class Task {
public:
    template<typename FUNCTION, typename ...ARGS>
    Task(FUNCTION &&f, ARGS ...args) {
        cout << "Task constructor" << endl;
        //bind, 将函数和可执行参数进行绑定
        this->f = bind(f, forward<ARGS>(args)...); //实现模板的时候不要忘记准确向前传递参数类型
    }
    void run() {
        f();
    }
private:
    function<void()> f;
};

int main() {
    int n = 8;
    //线程对象传入引用ref
    thread t1(add_one, ref(n)); //, t2(func, 30);
    t1.join();
    Task t2(add_one, ref(n));
    t2.run();
    t2.run();
    t2.run();
    //t2.join();
    cout << "hello world" << endl;
    cout << n << endl;
    return 0;
}
