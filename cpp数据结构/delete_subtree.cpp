/*************************************************************************
	> File Name: delete_subtree.cpp
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: 2020年10月18日 星期日 11时15分14秒
 ************************************************************************/

#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

template<typename Type> class Stack {
private:
    Type *data;
    int top_ind, size;
public:
    Stack(int size) {
        this->size = size;
        data = new Type[size];
        top_ind = -1;
    }
    ~Stack() {
        delete[] data;
    }
    void push(Type element) {
        if (top_ind >= size - 1) return ;
        data[++top_ind] = element;
        return ;
    }
    void pop() {
        if (top_ind < 0) return ;
        --top_ind;
        return ;
    }
    Type top() {
        return data[top_ind];
    }
};

template<typename Type> class Node {
public:
    Type data;
    Node<Type> *lchild, *rchild;
    Node(Type data) {
        this->data = data;
        lchild = NULL;
        rchild = NULL;
    }
    ~Node() {
        if (lchild != NULL) delete lchild;
        if (rchild != NULL) delete rchild;
    } 
    void output() {
        if (!this) return ;
        cout << data;
        if (lchild != NULL) {
            cout << '(';
            lchild->output();
            if (rchild == NULL) cout << ')';
        }
        if (rchild != NULL) {
            if (!lchild) cout << '(';
            cout << ',';
            rchild->output();
            cout << ')';
        }
        return ;
    }
    void delete_node(Node<Type>* &node, Type data) {
        if (!node) return ;
        if (node->data == data) {
            node->lchild = node->rchild = NULL;
            node = NULL;
            return ;
        }
        if (node->lchild) delete_node(node->lchild, data);
        if (node->rchild) delete_node(node->rchild, data);
        return ;
    }
};

template<typename Type> class BinaryTree {
private:
    Node<Type> *root;
public:
    BinaryTree() {
        root = NULL;
    }
    ~BinaryTree() {
        if (root != NULL) delete root;
    }
    void build(string str) {
        if (str.length() <= 0) return ;
        int k = -1;
        Node<Type> *p = new Node<Type>(0);
        Stack<Node<Type>*> stack(30);
        for (int i = 0; i < str.length(); ++i) {
            if (str[i] == '(') {k = 0; stack.push(p);}
            else if (str[i] == ',') k = 1;
            else if (str[i] == ')') stack.pop();
            else {
                Node<Type> *temp = new Node<Type>(str[i]);
                if (k == -1) {
                    root = temp;
                    stack.push(temp);
                }
                else if (k == 0) {
                    if (stack.top() == p) stack.pop();
                    stack.top()->lchild = temp;
                    stack.push(temp);
                }
                else {
                    stack.pop();
                    stack.top()->rchild = temp;
                    stack.push(temp);
                }
            }
        }
    }
    void output() {
        if (root == NULL) return ;
        root->output();
        return ;
    }
    void delete_subtree(Type data) {
        if (!root) return ;
        root->delete_node(root, data);
        return ;
    }
};

int main() {
    string tree;
    cin >> tree;
    BinaryTree<char> binarytree;
    binarytree.build(tree);
    string data;
    cin >> data;
    if (data.length() != 1) return 0;
    binarytree.delete_subtree(data[0]);
    binarytree.output();
    cout << endl;
    return 0;
}
