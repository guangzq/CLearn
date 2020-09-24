//
// Created by qiguang.zhu on 2020/9/24.
//
#include <iostream>

using namespace std;

int add(int a = 2, int b = 6) {
    return a + b;
}

double add(double a = 1, double b = 5) {
    return a + b;
}

int main() {
    cout << add(1.6, 1.1) << endl;
    cout << add(1, 9) << endl;
    cout << add(5) << endl;
    return 0;
}

