/*************************************************************************
	> File Name: my_hash.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sun 07 Mar 2021 07:14:07 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <functional>
#include <vector>
using namespace std;

class Hash_Table {
public:
    virtual void set_hash_function(function<int(string)>) = 0;
};

class Hash : public Hash_Table, public vector<int> {
public:
    void set_hash_function(function<int(string)> hashfunc) override {
        this->HASH = &hashfunc;
    }
    int operator[](string);
private:
    typedef int (*hash_func)(string);
    hash_func HASH;
    string key;
    int val;
};

int main() {
    return 0;
}
