/*************************************************************************
	> File Name: table_cirle_to_left.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 05 Dec 2020 03:47:10 PM CST
 ************************************************************************/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

template<typename Type> class Vector {
private:
    int size, length;
    Type *data;
public:
    Vector(int size) {
        this->size = size;
        length = 0;
        data = new Type[size];
    }
    ~Vector() {
        delete[] data;
    }
    void insert(int num) {
        if (length >= size) return;
        data[length++] = num;
    }
    void loop_move_left(int k) {
        if (k == 0 || k == size) return;
        Type *temp = new Type[k];
        for (int i = 0; i < k; i++) {
            temp[i] = data[i];
        }
        for (int i = k; i < length; i++) {
            data[i - k] = data[i];
        }
        for (int i = length - k; i < length; i++) {
            data[i] = temp[i - length + k];
        }
        delete[] temp;
    }
    void output() {
        for (int i = 0; i < length; i++) {
            i && cout << " ";
            cout << data[i];
        }
        cout << endl;
    }
};

int main() {
    int n, k, num;
    cin >> n >> k;
    Vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> num;
        v.insert(num);
    }
    v.loop_move_left(k);
    v.output();
    return 0;
}
