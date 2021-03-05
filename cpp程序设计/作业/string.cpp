/*************************************************************************
	> File Name: string.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 05 Mar 2021 07:42:47 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
using namespace std;

string s = "Kaikeba", s2 = "Haizei";

int main() {
    cout << s.find("a") << endl;
    cout << s.rfind("a") << endl << endl;

    cout << *s.insert(s.begin(), 'h') << endl;
    cout << s << endl;
    s.insert(1, s2);
    cout << s << endl << endl;

    cout << s.substr(1, 6) << endl;
    cout << s.substr(7) << endl << endl;

    cout << *s.erase(s.begin()) << endl;
    cout << s << endl;
    cout << *s.erase(s.begin(), s.begin() + 6) << endl;
    cout << s << endl;
    s.erase(3, 4);
    cout << s << endl << endl;

    s.append(s2);
    cout << s << endl;
    s.append(s2, 0, 3);
    cout << s << endl;
    s.append(3, '!');
    cout << s << endl << endl;

    s.replace(0, 3, "");
    cout << s << endl;
    return 0;
}
