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
int index[105], cnt, flag;

int is_nospam(int ind) {
    if (str[ind + 1] == 'o' && str[ind + 2] == 's' && str[ind + 3] == 'p'
        && str[ind + 4] == 'a' && str[ind + 5] == 'm') {
            return 1;
        }
    return 0;
}

int is_at(int ind) {
    if (ind != 0 && ind + 1 != str.length() - 1 && str[ind - 1] != '.' 
        && str[ind + 2] != '.' && str[ind + 1] == 't') return 1;
    return 0;
}

void answer() {
    for (int i = 1; i <= cnt; i++) {
        string s = str;
        ans[i] = s.replace(index[i], 2, "@");
    }
    if (flag) {
        for (int i = 1, j = cnt + 1; i <= cnt; i++, j++) {
            string s = ans[i];
            ans[j] = index[0] > index[i] ? s.replace(index[0] - 1, 6, "") : 
            s.replace(index[0], 6, "");
        } 
    }
    return ;
}

bool cmp(string str1, string str2) {
    return str1 < str2;
}

void output(int num) {
    for (int i = 1; i <= num; i++) {
        cout << ans[i] << endl;
    }
    return ;
}

int main() {
    cin >> str;
    for (int i = 0; str[i]; i++) {
        if (str[i] == 'n' && is_nospam(i)) {
            index[0] = i;
            i += 5;
            flag = 1;
        }
        else if (str[i] == 'a' && is_at(i)) {
            cnt++;
            index[cnt] = i;
            i += 1;
        }
    }
    answer();
    if (flag) {
        sort(ans + 1, ans + (cnt << 1) + 1, cmp);
        output((cnt << 1));
    } else {
        sort(ans + 1, ans + cnt + 1, cmp);
        output(cnt);
    }
    return 0;
}
