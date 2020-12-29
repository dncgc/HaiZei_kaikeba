/*************************************************************************
	> File Name: sort.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Tue 29 Dec 2020 06:14:13 PM CST
 ************************************************************************/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct node{
    int cnt;
    string num;
};

bool cmp(int a, int b) {
    //期待的排序后前面一个数与后面一个数的关系
    return a > b;
}

//对自定义类型排序,使用引用可避免拷贝
bool cmp2(const node &a, const node &b) {
    if (a.num.size() == b.num.size()) {
        return a.num > b.num;//>按照字典序比较两个字符串大小
    }
    return a.num.size() > b.num.size();
}

int main() {
    /*
    int n, num[1005];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num, num + n, cmp);
    for (int i = 0; i < n; i++) {
        cout << num[i] << " ";
    }
    cout << endl;
    */
    int n;
    node bio[105];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> bio[i].num;
        bio[i].cnt = i + 1;
    }
    sort(bio, bio + n, cmp2);
    cout << bio[0].cnt << endl << bio[0].num << endl;
    return 0;
}
