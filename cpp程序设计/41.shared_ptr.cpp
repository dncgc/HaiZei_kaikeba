/*************************************************************************
	> File Name: 41.shared_ptr.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 27 Mar 2021 08:42:03 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

namespace haizei {

class shared_ptr_base_data {
public:
    shared_ptr_base_data(int cnt = 0, void *ptr = nullptr) : cnt(new int(cnt)), ptr(ptr) {}
    int use_cnt() { return *cnt; }
    void *get() { return ptr; }
    virtual void destory_ptr() {
        cout << this << endl;
        throw runtime_error("delete nullptr shared_ptr error");
        return ;
    }
    void sub_one() {
        if (this == data_nullptr) return ;
        *cnt -= 1;
        if (*cnt == 0) delete this;
        return ;
    }
    virtual ~shared_ptr_base_data() {
        delete cnt;
        if (this == data_nullptr) return ;
        this->destory_ptr();
    }
    static shared_ptr_base_data *data_nullptr;

protected:
    int *cnt;
    void *ptr;
};
shared_ptr_base_data *shared_ptr_base_data::data_nullptr = new shared_ptr_base_data();

template<typename T>
class shared_ptr_data : public shared_ptr_base_data {
public:
    shared_ptr_data(int cnt, T *ptr) : shared_ptr_base_data(cnt, ptr) {}
    void destory_ptr() override {
        delete (T *)ptr;
        return ;
    }

};

template<typename T>
class shared_ptr {
public:
    shared_ptr(T *ptr) {
        if (ptr == nullptr) {
            data = shared_ptr_base_data::data_nullptr;
            return ;
        }
        data = new shared_ptr_data<T>(1, ptr);
        return ;
    }
    T *operator->() { return (T *)data->get(); }
    shared_ptr<T> &operator=(T *ptr) {
        if (ptr == nullptr) {
            data = shared_ptr_base_data::data_nullptr;
            return *this;
        }
        data->sub_one();
        data = new shared_ptr_data<T>(1, ptr);
        return *this;
    }

private:
    shared_ptr_base_data *data;
};

} // end of haizei

class A {
public:
    int x, y;
    ~A() {
        cout << "class A destructor" << endl;
    }
};

int main() {
    haizei::shared_ptr<A> p = new A();
    p->x = 123;
    p->y = 456;
    cout << p->x << " " << p->y << endl;
    cout << &haizei::shared_ptr_base_data::data_nullptr << endl;
    p = new A();
    return 0;
}
