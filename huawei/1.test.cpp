/*************************************************************************
	> File Name: 1.test.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Thu 06 May 2021 03:07:39 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

int preval = 0x80000000;
bool isValidBST(struct TreeNode *root) {
    if (root == nullptr) return true;
    int flag = true;
    flag = flag && isValidBST(root->left);
    if (root->val <= preval) return false;
    preval = root->val;
    flag = flag && isValidBST(root->right);
    return flag;
}
