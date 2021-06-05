/*************************************************************************
	> File Name: 8.postorder.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Fri 19 Mar 2021 11:36:38 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

void post_order(Node *root) {
    if (root == NULL) return ;
    post_order(root->lchild);
    post_order(root->rchild);
    output(root);
    return ;
}

int main() {
    return 0;
}
