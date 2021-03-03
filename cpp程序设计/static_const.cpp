/*************************************************************************
	> File Name: static_const.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 03 Mar 2021 08:45:14 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class People {
public:
    People() : say_cnt(0) {
        People::total_num += 1; //如果遇到重名，可以写成People::total_num
    }
    static void say_count() {
        cout << People::total_num << endl;
    }
    void say() const { //const 方法内不能更改成员属性, 也不能调用非const类型方法
        cout << "hahaha, funy!" << endl;
        output();
        say_cnt += 1; //say_cnt 的改变是逻辑上的const
        return ;
    }
    void output() {
        cout << "output function" << endl;
    }
    void output() const {
        cout << "const output function" << endl;
    }
    ~People() {
        People::total_num -= 1;
    }
private:
    mutable int say_cnt; //不归入数据意义上的管辖，逻辑上的const
    static int total_num;  //类属性的声明
};

int People::total_num = 0; //类属性的定义

int main() {
    People hug, xiao_hug;
    hug.say_count();
    People::say_count();
    {
        People hug, xiao_hug;
        People::say_count();
    }
    People::say_count();
    const People xiaobo; //const 类型的对象不能调用非const类型的方法
    xiaobo.say();
    return 0;
}
