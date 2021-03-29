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
    shared_ptr_base_data(int cnt = 0) : cnt(new int(cnt)) {}
    int use_cnt() { return *cnt; }
    virtual void *get() { return nullptr; }
    void sub_one() {
        if (this == data_nullptr) return ;
        *cnt -= 1;
        if (*cnt == 0) delete this;
        return ;
    }
    void add_one() {
        if (this == data_nullptr) return ;
        *cnt += 1;
        return ;
    }
    virtual ~shared_ptr_base_data() {
        delete cnt;
    }
    static shared_ptr_base_data *data_nullptr;

protected:
    int *cnt;
};
shared_ptr_base_data *shared_ptr_base_data::data_nullptr = new shared_ptr_base_data();

template<typename T>
class shared_ptr_data : public shared_ptr_base_data {
public:
    shared_ptr_data(int cnt, T *ptr) : shared_ptr_base_data(cnt), ptr(ptr) {}
    void *get() override { return ptr; };
    ~shared_ptr_data() {
        delete ptr;
    }
private:
    T *ptr;
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
    shared_ptr(const shared_ptr<T> &p) : data(p.data) {
        data->add_one();
    }
    T *operator->() { return (T *)data->get(); }
    shared_ptr<T> &operator=(T *ptr) {
        data->sub_one();
        if (ptr == nullptr) {
            data = shared_ptr_base_data::data_nullptr;
            return *this;
        }
        data = new shared_ptr_data<T>(1, ptr);
        return *this;
    }
    T &operator*() { return *((T *)data->get()); }
    int use_cnt() {
        return data->use_cnt();
    }
    ~shared_ptr() {
        data->sub_one();
    }

private:
    shared_ptr_base_data *data;
};

} // end of haizei

class A {
public:
    int x, y;
    A() {
        cout << this << "class A constructor" << endl;
    }
    ~A() {
        cout << this << "class A destructor" << endl;
    }
};

int main() {
    haizei::shared_ptr<A> p = new A();
    p->x = 123;
    p->y = 456;
    cout << p->x << " " << p->y << endl;
    cout << (*p).x << " " << (*p).y << endl;
    cout << p.use_cnt() << endl;
    haizei::shared_ptr<A> q = p;
    cout << p.use_cnt() << endl;
    cout << &haizei::shared_ptr_base_data::data_nullptr << endl;
    p = new A();
    p = nullptr;
    return 0;
}
