/*************************************************************************
	> File Name: 39.single.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 27 Mar 2021 06:27:28 PM CST
 ************************************************************************/

//单例模式的饿汉模式

#include <iostream>
#include <mutex>
using namespace std;

class SingleInstance {
public:
    //1.能够访问私有方法与属性 2.是类方法，不依赖于对象，能单独执行
    static SingleInstance *getInstance() {
        if (single == nullptr) { //考虑线程安全情况下的线程效率问题
            unique_lock<mutex> lock(Instance_mutex);
            if (single == nullptr) {
                single = new SingleInstance();
            }
        }
        return single;
    }

private:
    SingleInstance() {} //构造函数私有化
    SingleInstance(const SingleInstance &) = delete; //删除拷贝构造，使其类内类外都不能被拷贝
    static SingleInstance *single;
    static mutex Instance_mutex; //互斥锁，实现线程安全，防止多线程情况下建立多个对象
};

SingleInstance *SingleInstance::single = nullptr;
mutex SingleInstance::Instance_mutex;

int main() {
    SingleInstance *s1 = SingleInstance::getInstance();

    return 0;
}
