//
// Created by qiguang.zhu on 2020/9/24.
//
#include <iostream>

using namespace std;

template<class T1, class T2>
T1 add(T1 a, T2 b) {
    cout << sizeof(a) << " , " << sizeof(b) << "\t";
    return a + b;
}

int main() {
    cout << add(1, 5) << endl;
    cout << add(1.2, 1.5) << endl;
    cout << add('A', 2) << endl;
    return 0;
}

