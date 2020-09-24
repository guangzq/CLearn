//
// Created by qiguang.zhu on 2020/9/24.
//
#include <iostream>

using namespace std;

inline int Max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    cout << Max(1, 2) << endl;
    cout << Max(6, 5) << endl;
    return 0;
}

