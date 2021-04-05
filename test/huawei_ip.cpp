/*************************************************************************
	> File Name: huawei_ip.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Mon 05 Apr 2021 11:03:15 AM CST
 ************************************************************************/

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int a, b, c, d, e, error, s, num[10];

union test {
    int num;
    char ch[4];
} t;

void str_to_nums(string &s, int *num) {
    for (int i = 0, j = -1, ind = 0; i <= s.length(); i++) {
        if (s[i] == '.' || s[i] == '~' || s[i] == 0) {
            if (i == j + 1) num[ind++] = -1;
            else num[ind++] = atoi((s.substr(j + 1, i).c_str()));
            j = i;        
        }
    }
}

bool isvalid(int n) {
    if (n == -1 || n == 0) return false;
    while (n & 0x80000000) n <<= 1;   
    return n == 0;
}

int main() {
    string str;
    while (cin >> str) {
        int flag = 0;
        str_to_nums(str, num);
        for (int i = 0; i < 8; i++) {
            if (num[i] < 0 || num[i] > 255) { 
                flag = 1;
                break;
            }
        }
        if (flag) {
            error++; 
            continue;    
        } else {
            t.ch[0] = num[7];
            t.ch[1] = num[6];
            t.ch[2] = num[5];
            t.ch[3] = num[4];
            if (!isvalid(t.num)) flag = 1;
        }
        if (flag) {
            error++;
            continue;
        } else {
            if (num[0] >= 1 && num[0] <= 126) a++;
            else if (num[0] >= 128 && num[0] <= 191) b++;
            else if (num[0] >= 192 && num[0] <= 223) c++;
            else if (num[0] >= 224 && num[0] <= 239) d++;
            else if (num[0] >= 240 && num[0] <= 255) e++;
            if (num[0] == 10 || (num[0] == 172 && num[1] >= 16 && num[1] <= 31)
                || (num[0] == 192 && num[1] == 168)) s++;    
        }   
    }
    cout << a << " " << b << " " << c << " " << d << " " << e << " " << error << " " << s << endl;
    return 0;
}
