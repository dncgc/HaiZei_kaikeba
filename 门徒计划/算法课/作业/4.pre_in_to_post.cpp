/*************************************************************************
	> File Name: 4.pre_in_to_post.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Wed 07 Apr 2021 11:09:27 AM CST
 ************************************************************************/

#include <iostream>
#include <vector>
using namespace std;

int pre[7000], in[3500];
vector<int> post;

void pre_in_to_post(int *p, int p_l, int p_r, int *inorder, int i_l, int i_r) {
    if (p_l > p_r || i_l > i_r) return ;
    if (p_l == p_r) { post.push_back(p[p_l]); return ; }
    int root = p[p_l], pos;
    for (int i = i_l; i <= i_r; i++) {
        if (inorder[i] == root) {
            pos = i;
            break;
        }
    }
    pre_in_to_post(p, p_l + 1, p_l + pos - i_l, inorder, i_l, pos - 1);
    pre_in_to_post(p, p_l + pos - i_l + 1, p_r, inorder, pos + 1, i_r);
    post.push_back(p[p_l]);
    return ;
}

int main() {
    int cnt = 0;
    long long ans = 0;
    while(~scanf("%d", pre + cnt)) cnt++;
    for (int i = (cnt >> 1), j = 0; i < cnt; i++, j++) {
        in[j] = pre[i];
    }
    cnt >>= 1;
    pre_in_to_post(pre, 0, cnt - 1, in, 0, cnt - 1);
    for (int i = 0; i < post.size(); i++) {
        ans += post[i] * (i + 1);
    }
    cout << ans << endl;
    return 0;
}
