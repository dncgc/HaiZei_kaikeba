/*************************************************************************
	> File Name: 39.single.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 27 Mar 2021 06:27:28 PM CST
 ************************************************************************/

//单例模式的懒汉模式，实现简单,不用考虑加锁、线程效率，
//但不管对象有没有用到，都会初始化出来，资源利用效率不精准，程序启动速度慢，
//更推荐饿汉模式

#include <iostream>
#include <mutex>
using namespace std;

class SingleInstance {
public:
    //1.能够访问私有方法与属性 2.是类方法，不依赖于对象，能单独执行
    static SingleInstance *getInstance() {
        static bool flag = true;
        if (flag) {
            flag = false;
            single = new SingleInstance();
        }
        return single;
    }

private:
    SingleInstance() {} //构造函数私有化
    SingleInstance(const SingleInstance &) = delete; //删除拷贝构造，使其类内类外都不能被拷贝
    static SingleInstance *single;
};

SingleInstance *SingleInstance::single = SingleInstance::getInstance();

int main() {
    SingleInstance *s = SingleInstance::getInstance();

    return 0;
}
