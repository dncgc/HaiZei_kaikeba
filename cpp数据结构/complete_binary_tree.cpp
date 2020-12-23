/*************************************************************************
	> File Name: complete_binary_tree.cpp
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: 2020年11月11日 星期三 19时06分50秒
 ************************************************************************/

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

template<typename Type> class TreeNode {
private:
    Type data;
    TreeNode<Type> *lchild, *rchild;
public:
    TreeNode(Type data) {
        this->data = data;
        lchild = rchild = NULL;
    }
    ~TreeNode() {
        if (lchild) delete lchild;
        if (rchild) delete rchild;
    }
    void buildlchild(TreeNode<Type> *node) {
        lchild = node;
        return ;
    }
    void buildrchild(TreeNode<Type> *node) {
        rchild = node;
        return ;
    }
    void output() {
        if (!this) return ;
        cout << data;
        if (lchild) {
            cout << '(';
            lchild->output();
            if (!rchild) cout << ')';
        }
        if (rchild) {
            if (!lchild) cout << '(';
            cout << ',';
            rchild->output();
            cout << ')';
        }
        return ;
    }
};

template<typename Type> class BinaryTree {
private:
    TreeNode<Type> *root;
public:
    BinaryTree() {
        root = NULL;
    }
    ~BinaryTree() {
        if (root) delete root;
    }
    void output() {
        root->output();
        return ;
    }
    void build(TreeNode<Type> **nodes, int n) {
        for (int i = 1; i < n; ++i) {
            if (i == 1) root = nodes[i];
            else if (i & 1) nodes[i >> 1]->buildrchild(nodes[i]);
            else nodes[i >> 1]->buildlchild(nodes[i]);
        }
    }
};

TreeNode<char> **nodes = new TreeNode<char>*[100];

int main() {
    char input;
    BinaryTree<char> binarytree;
    int n = 1;
    while (1) {
        cin >> input;
        if (input == '$') break;
        if (input == ' ') continue;
        TreeNode<char> *node = new TreeNode<char>(input);
        nodes[n++] = node;
    }
    binarytree.build(nodes, n);
    binarytree.output();
    cout << endl;
    return 0;
}
