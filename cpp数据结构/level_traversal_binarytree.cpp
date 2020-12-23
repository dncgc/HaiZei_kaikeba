/*************************************************************************
	> File Name: level_traversal_binarytree.cpp
	> Author: Guochong Cui
	> Mail: gc_cui@seu.edu.cn
	> Created Time: 2020年11月11日 星期三 19时56分54秒
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
    bool isempty() {
        return cnt == 0;
    }
    int getcnt() {
        return cnt;
    }
};

template<typename Type> class Stack {
private:
    Type *data;
    int top, size;
public:
    Stack(int size) {
        data = new Type[size];
        this->size = size;
        top = -1;
    }
    ~Stack() {
        if (data) delete[] data;
    }
    Type gettop() {
        return data[top];
    }
    void push(Type element) {
        if (top == size - 1) return ;
        data[++top] = element;
        return ;
    }
    void pop() {
        if (top < 0) return ;
        --top;
        return ;
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
        if (lchild) lchild = NULL;
        if (rchild) rchild = NULL;
    }
};

template<typename Type> class BinaryTree {
private:
    TreeNode<Type> *root;
public:
    BinaryTree(){
        root = NULL;
    }
    ~BinaryTree() {
        if (root) delete root;
    }
    void build(string tree) {
        int flag = -1;
        TreeNode<Type> *p = new TreeNode<Type>(0);
        Stack<TreeNode<Type>*> stack(100);
        for (int i = 0; i < tree.length(); ++i) {
            if (tree[i] == '(') {
                flag = 0;
                stack.push(p);
            }
            else if (tree[i] == ',') flag = 1;
            else if (tree[i] == ')') stack.pop();
            else {
                TreeNode<Type> *temp = new TreeNode<Type>(tree[i]);
                if (flag == -1) {
                    root = temp;
                    stack.push(temp);
                }
                else if (flag == 0) {
                    if (stack.gettop() == p) stack.pop();
                    stack.gettop()->lchild = temp;
                    stack.push(temp);
                }
                else {
                    stack.pop();
                    stack.gettop()->rchild = temp;
                    stack.push(temp);
                }
            }
        }
    }
    void output() {
        if (!root) return ;
        Queue<TreeNode<Type>*> queue(100);
        queue.push(root);
        while(!queue.isempty()) {
            for (int i = 0; i < queue.getcnt(); ++i) {
                if (queue.top()->lchild) queue.push(queue.top()->lchild);
                if (queue.top()->rchild) queue.push(queue.top()->rchild);
                cout << queue.top()->data << ' ';
                queue.pop();
            }
        }
        cout << endl;
    }
};

int main() {
    string tree;
    cin >> tree;
    BinaryTree<char> binarytree;
    binarytree.build(tree);
    binarytree.output();
    return 0;
}
