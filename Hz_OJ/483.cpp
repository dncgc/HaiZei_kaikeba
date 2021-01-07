/*************************************************************************
	> File Name: 483.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 06 Jan 2021 09:54:18 PM CST
 ************************************************************************/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string str, ans[205];
int index[105], cnt, cnt_n;

int is_nospam(int ind) {
    if (str[ind + 1] == 'o' && str[ind + 2] == 's' && str[ind + 3] == 'p'
        && str[ind + 4] == 'a' && str[ind + 5] == 'm') {
            return 1;
        }
    return 0;
}

int is_ok(string s) {
    if (s[0] == '@' || s[s.length() - 1] == '@' || 
        s[0] == '.' || s[s.length() - 1] == '.') {
            return 1;
        }
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '@') {
            if (s[i - 1] == '.' || s[i + 1] == '.') return 1;
            break;
        }
    }
    return 0;
}

void answer(string str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] == 'a' && str[i + 1] == 't') {
            string s = str;
            ans[++cnt] = s.replace(i, 2, "@");
            i += 1;
        }
    }
    return ;
}

bool cmp(string str1, string str2) {
    return str1 < str2;
}

void output() {
    for (int i = 1; i <= cnt; i++) {
        if (is_ok(ans[i]) || ans[i] == ans[i - 1]) continue;
        cout << ans[i] << endl;
    }
    return ;
}

int main() {
    cin >> str;
    for (int i = 0; str[i]; i++) {
        if (str[i] == 'n' && is_nospam(i)) {
            index[++cnt_n] = i;
            i += 5;
        }
    }
    answer(str);
    for (int i = 1; i <= cnt_n; i++) {
        string s = str;
        string ss = s.replace(index[i], 6, "");
        answer(ss);
    }
    sort(ans + 1, ans + cnt + 1, cmp);
    output();
    return 0;
}
