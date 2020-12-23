/*************************************************************************
	> File Name: three_label_build_binarytree.cpp
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: 2020年11月11日 星期三 20时46分09秒
 ************************************************************************/

#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

template<typename Type> class Queue {
private:
    Type *data;
    int size, head, tail, cnt;
public:
    Queue(int size) {
        data = new Type[size];
        this->size = size;
        head = tail = cnt = 0;
    }
    ~Queue() {
        if (data) delete[] data;
    }
    Type top() {
        return data[head];
    }
    void push(Type element) {
        if (cnt == size) return ;
        data[tail++] = element;
        if (tail == size) tail = 0;
        ++cnt;
        return ;
    }
    void pop() {
        if (!cnt) return ;
        ++head;
        if (head == size) head = 0;
        --cnt;
        return ;
    }
    Type find(char element) {
        while (data[head]->lchild && data[head]->rchild) ++head;
        for (int i = head; i <= tail; ++i) {
            if (data[i]->data != element) continue;
            return data[i];
        }
        return 0;
    }
};

template<typename Type> class TreeNode {
public:
    Type data;
    TreeNode<Type> *lchild, *rchild;

    TreeNode(Type data) {
        this->data = data;
        lchild = rchild = NULL;
    }
    ~TreeNode() {
        if (lchild) delete lchild;
        if (rchild) delete rchild;
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
    void buildroot(TreeNode<Type>* node) {
        root = node;
        return ;
    }
    void output() {
        root->output();
        return ;
    }
};

int main() {
    string treenode;
    BinaryTree<char> binarytree;
    Queue<TreeNode<char>*> queue(100);
    while(1) {
        cin >> treenode;
        if (treenode[0] == '^') {
            if (treenode[1] == '^') break;
            else {
                TreeNode<char> *temp = new TreeNode<char>(treenode[1]);
                binarytree.buildroot(temp);
                queue.push(temp);
                continue;
            }
        }
        TreeNode<char> *temp = new TreeNode<char>(treenode[1]);
        if(treenode[2] == 'L') queue.find(treenode[0])->lchild = temp;
        else if (treenode[2] == 'R') queue.find(treenode[0])->rchild = temp;
        queue.push(temp);
    }
    binarytree.output();
    cout << endl;
    return 0;
}
