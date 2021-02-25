//
// Created by qiguang.zhu on 2021/2/24.
//
#include <iostream>

using namespace std;
class dec {
    void test() {
        int a = 1;
        decltype(a) b = 2;//根据a int类型推导出b为int


    }
};

int main() {
    auto i = 10;//auto推导为int
    auto a = &i;//auto推导为int*
    auto b = 10.5;//auto推导为double
    auto str = "this is str";//auto推导为const char *常量指针
    return 0;
}

