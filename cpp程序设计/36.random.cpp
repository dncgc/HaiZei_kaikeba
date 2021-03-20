/*************************************************************************
	> File Name: 36.random.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 20 Mar 2021 10:38:56 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

namespace haizei {
    static int __seed = 3;
    void srand(int seed) {
        __seed = seed;
        return ;
    }
    int rand() {
        return (__seed = __seed * 3 % 101);
    }
} // end of haizei

int main() {
    int n;
    while (cin >> n) {
        haizei::srand(n);
        for (int i = 0; i < 10; i++) {
            cout << haizei::rand() << endl;
        }
    }
    return 0;
}
