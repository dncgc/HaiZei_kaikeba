/*************************************************************************
	> File Name: 40.visitor.cpp
	> Author: Cui Guochong
	> Mail: gc_cui@seu.edu.cn
	> Created Time: Sat 27 Mar 2021 07:17:55 PM CST
 ************************************************************************/

#include <iostream>
using namespace std;

class A;
class B;
class C;
class D;
class E;
class F;
class G;

class Base {
public:
    class IVisitor {
    public:
        virtual void visit(A *) = 0;
        virtual void visit(B *) = 0;
        virtual void visit(C *) = 0;
        virtual void visit(D *) = 0;
        virtual void visit(E *) = 0;
        virtual void visit(F *) = 0;
        virtual void visit(G *) = 0;
    };
    virtual void say() = 0;
    virtual void Accept(IVisitor *) = 0;
    virtual ~Base() {}
};

class A : public Base{
public:
    void say() override {
        cout << "Class A" << endl;
    }
    void Accept(IVisitor *vis) override {
        vis->visit(this);
        return ;
    }
};

class B : public Base{
public:
    void say() override {
        cout << "Class B" << endl;
    }
    void Accept(IVisitor *vis) override {
        vis->visit(this);
        return ;
    }
};

class C : public Base{
public:
    void say() override {
        cout << "Class C" << endl;
    }
    void Accept(IVisitor *vis) override {
        vis->visit(this);
        return ;
    }
};

class D : public Base{
public:
    void say() override {
        cout << "Class D" << endl;
    }
    void Accept(IVisitor *vis) override {
        vis->visit(this);
        return ;
    }
};

class E : public Base{
public:
    void say() override {
        cout << "Class E" << endl;
    }
    void Accept(IVisitor *vis) override {
        vis->visit(this);
        return ;
    }
};
class F : public Base{
public:
    void say() override {
        cout << "Class F" << endl;
    }
    void Accept(IVisitor *vis) override {
        vis->visit(this);
        return ;
    }
};
class G : public Base{
public:
    void say() override {
        cout << "Class G" << endl;
    }
    void Accept(IVisitor *vis) override {
        vis->visit(this);
        return ;
    }
};

class outputVisitor : public Base::IVisitor {
public:
    void visit(A *obj) {
        cout << "func A" << endl;
    }
    void visit(B *obj) {
        cout << "func B" << endl;
    }
    void visit(C *obj) {
        cout << "func C" << endl;
    }
    void visit(D *obj) {
        cout << "func D" << endl;
    }
    void visit(E *obj) {
        cout << "func E" << endl;
    }
    void visit(F *obj) {
        cout << "func F" << endl;
    }
    void visit(G *obj) {
        cout << "func G" << endl;
    }
};

class clacVisitor : public Base::IVisitor {
public:
    clacVisitor(int &x) : x(x) {}
    void visit(A *obj) {
        x *= 2;
    }
    void visit(B *obj) {
        x -= 3;
    }
    void visit(C *obj) {
        x += 6;
    }
    void visit(D *obj) {
        x /= 3;
    }
    void visit(E *obj) {
        x -= 2;
    }
    void visit(F *obj) {
        x += 5;
    }
    void visit(G *obj) {
        x *= 3;
    }
    int &x;
};
/*
void func_A() {
    cout << "func A" << endl;
}
void func_B() {
    cout << "func B" << endl;
}
void func_C() {
    cout << "func C" << endl;
}
void func_D() {
    cout << "func D" << endl;
}
void func_E() {
    cout << "func E" << endl;
}
*/
int main() {
    srand(time(0));
    Base *p[5] = {nullptr};
    for (int i = 0; i < 5; i++) {
        switch (rand() % 5) {
            case 0: p[i] = new A(); break;
            case 1: p[i] = new B(); break;
            case 2: p[i] = new C(); break;
            case 3: p[i] = new D(); break;
            case 4: p[i] = new E(); break;
        }
    }
    int x = 1;
    clacVisitor vis(x);
    for (int i = 0, pre = x; i < 5; i++) {
        p[i]->Accept(&vis);
        p[i]->say();
        cout << pre << "->" << x << endl;
        pre = x;
    }
    //p->say();
    /*
    //这种写法日后维护成本特别高，新增子类很有可能忘记修改这种地方，导致bug
    //而且效率较低
    if (dynamic_cast<A *>(p)) {
        func_A();
    } else if (dynamic_cast<B *>(p)) {
        func_B();
    } else if (dynamic_cast<C *>(p)) {
        func_C();
    } else if (dynamic_cast<D *>(p)) {
        func_D();
    } else if (dynamic_cast<E *>(p)) {
        func_E();
    }*/
    //outputVisitor vis;
    //p->Accept(&vis);
    return 0;
}
