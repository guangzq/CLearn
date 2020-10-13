//
// Created by qiguang.zhu on 2020/10/13.
//
#include <iostream>
class A {
public:
    int key;
};
class B:  virtual public A {

};
class C:  virtual public A {

};
class D : public B, public C {

};
int main() {
    D d1;
    d1.key = 6;
    return 0;
}

