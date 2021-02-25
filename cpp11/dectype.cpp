//
// Created by qiguang.zhu on 2021/2/24.
//
#include <iostream>
using namespace std;
class Base {
public:
    Base(){}
    int x;
};
int main() {
    const Base obj;
    decltype(obj.x) b = 1;//符合规则一，a的类型推导为int
    decltype((obj.x)) c = b;//符合规则三，c的类型推导为int&
    return 0;
}

